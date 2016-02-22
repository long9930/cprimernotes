# MPI

## Hellow World

#### mpieg01.c


```c
#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);

    // Print off a hello world message
    printf("Hello world from processor %s, rank %d"
           " out of %d processors\n",
           processor_name, world_rank, world_size);

    // Finalize the MPI environment.
    MPI_Finalize();
}

```

In command line

```bash
> mpicc mpieg01.c -o main
> mpirun -n 4 ./main
```


#### mpieg02.c

```c
#include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {

    cout << "Before initilization !! \n \n";

    
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);


    cout << "This is from rank " << world_rank << "\n";
    // Finalize the MPI environment.
    MPI_Finalize();
}
```

In command line

```bash
> mpicxx mpieg02.cpp -o main
> mpirun -n 4 ./main
```

#### mpieg03.c

``` bash
#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int i;
    for(i= world_rank; i<30; i+=world_size){
	printf("Rank %d is processing loop %d \n",  world_rank, i);
    }

    // Finalize the MPI environment.
    MPI_Finalize();
}
```


Result

```
> mpicc mpieg03.c -o main
> mpirun -n 4 ./main
Rank 0 is processing loop 0 
Rank 0 is processing loop 4 
Rank 0 is processing loop 8 
Rank 0 is processing loop 12 
Rank 0 is processing loop 16 
Rank 0 is processing loop 20 
Rank 0 is processing loop 24 
Rank 0 is processing loop 28 
Rank 1 is processing loop 1 
Rank 1 is processing loop 5 
Rank 1 is processing loop 9 
Rank 1 is processing loop 13 
Rank 1 is processing loop 17 
Rank 1 is processing loop 21 
Rank 1 is processing loop 25 
Rank 1 is processing loop 29 
Rank 2 is processing loop 2 
Rank 2 is processing loop 6 
Rank 2 is processing loop 10 
Rank 2 is processing loop 14 
Rank 2 is processing loop 18 
Rank 2 is processing loop 22 
Rank 2 is processing loop 26 
Rank 3 is processing loop 3 
Rank 3 is processing loop 7 
Rank 3 is processing loop 11 
Rank 3 is processing loop 15 
Rank 3 is processing loop 19 
Rank 3 is processing loop 23 
Rank 3 is processing loop 27 
```

## Benchmark

Sequential programming

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char* argv[])
{
    int i, niter = 400000000;
    double x,y, z, pi, timee;
    int count=0;
    struct timeval tvBegin, tvEnd;

    gettimeofday(&tvBegin, NULL);
    srand( (unsigned) time(NULL));
    //main loop
    for (i=0; i<niter; ++i)
    {
        //get random points
        x = (double) rand()/RAND_MAX;
        y = (double) rand()/RAND_MAX;
        z = (x*x)+(y*y);
        //check to see if point is in unit circle
        if (z<=1)
        {
            ++count;
        }
    }
    pi = ((double)count/(double)niter)*4.0;          //p = 4(m/n)
    gettimeofday(&tvEnd, NULL);
    timee = (tvEnd.tv_sec - tvBegin.tv_sec)*1000000 +
	tvEnd.tv_usec - tvBegin.tv_usec;
    timee = timee /1000;
    printf("Pi: %.20f\n", pi);
    printf("Time elapsed is %f milliseconds. \n", timee);
    
    return 0;
}
```

Parallel Programming

```c
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
 
int main(int argc, char* argv[])
{
    int i, niter = 400000000;
    double x,y, z, pi, timeElapsed;
    int count=0, global_count=0;


    struct timeval tvBegin, tvEnd, tvDiff;
    gettimeofday(&tvBegin, NULL);
    
    MPI_Init(&argc, &argv);
    MPI_Barrier(MPI_COMM_WORLD);

    int ID, nThreads;
    MPI_Comm_rank(MPI_COMM_WORLD, &ID);
    MPI_Comm_size(MPI_COMM_WORLD, &nThreads);

    // set random seed by thread ID
    srand( (unsigned) time(NULL) + ID);
    
    //main loop
    for (i=ID; i<niter; i+=nThreads)
    {
        //get random points
        x = (double) rand()/RAND_MAX;
        y = (double) rand()/RAND_MAX;
        z = x*x + y*y;
        if (z<=1)  ++count;
    }

    MPI_Reduce(&count, &global_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    gettimeofday(&tvEnd, NULL);

    printf("Count in thread %d is %d \n", ID, count);
    
    
    MPI_Finalize();
    //only the root thread will output
    if(ID==0){
	pi = ((double) global_count/ (double) niter) * 4.0;          //p = 4(m/n)
	printf("Pi: %.20f\n", pi);
	timeElapsed = (tvEnd.tv_sec - tvBegin.tv_sec)*1000000 +
	    tvEnd.tv_usec - tvBegin.tv_usec;    
	printf("Time elapsed is %f milliseconds. \n", timeElapsed/1000);
    }

    return 0;
}
```

In command line


```bash
> gcc benchmark1.c -o sequential -Wall
> ./sequential
Pi: 3.14162781000000013165
Time elapsed is 9089.656000 milliseconds. 

> mpicc benchmark2.c -o main -Wall
> mpirun -n 2 ./main
Count in thread 1 is 157079085 
Count in thread 0 is 157074284 
Pi: 3.14153369000000015632
Time elapsed is 4882.055000 milliseconds. 

> mpirun -n 4 ./main
Count in thread 1 is 78538157 
Count in thread 3 is 78549240 
Count in thread 2 is 78540124 
Count in thread 0 is 78539997 
Pi: 3.14167518000000001166
Time elapsed is 2943.401000 milliseconds. 
```