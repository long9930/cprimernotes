#OpenMP


## Parallel Region

The code in the parallel construct will be executed repeatedly across threads. But the order of the exucutation can not be expected.


The file ```eg01.c```.

```c
#include <omp.h>
#include <stdio.h>

int main(int argc, char **argv){
    #pragma omp parallel
    {
		int ID = omp_get_thread_num();
		printf("hello(%d)",ID);
		printf("world(%d)\n", ID);
    }
    return 0;
}

```

In command line, compile with link ```-fopenmp```.

```bash
> gcc -o main -fopenmp eg01.cpp
> export OMP_NUM_THREADS=4
> ./main
hello(3)hello(1)hello(0)hello(2)world(3)
world(1)
world(0)
world(2)
```

## Parallel For
The *loop worksharing construct* splits up loop iterationsa among the threads in a team.


The ```eg02.c``` file

```c
#include <omp.h>
#include <stdio.h>

int main(int argc, char **argv){
    #pragma omp parallel
    {
	int ID = omp_get_thread_num();
	int i;
	#pragma omp for
	for(i=0; i<10; i++)	    
	    printf("Thread %d is processing iter %d\n",ID, i);
	
    }
    return 0;
}
```


In command line

```bash
>gcc eg02.c -o main -fopenmp
>./main
Thread 1 is processing iter 3
Thread 2 is processing iter 6
Thread 0 is processing iter 0
Thread 3 is processing iter 8
Thread 1 is processing iter 4
Thread 2 is processing iter 7
Thread 0 is processing iter 1
Thread 3 is processing iter 9
Thread 1 is processing iter 5
Thread 0 is processing iter 2
```


## Compute the Convolution
Data is shared across the threads by default.

Use ```reduction(Opt:Var)```. Private variable ```var``` will be created for each thread.

| Operator | Initial Value |
|----------|---------------|
| +        |  0            |
| -        |  0            |
| *        |  1            |


```c
#include <omp.h>
#include <stdio.h>

int main(int argc, char **argv){
    int a[] = {8,10,3,5,7,10,1,33,50,1,2,3,4,5,6,7,8,9,10};
    int b[] = {3,2,99,4,8,22,41,9,78,10,9,8,7,6,5,4,3,2,1};
    int n = sizeof(a)/sizeof(a[0]);
    int c,i;

    // value is shared
    #pragma opm parallel for
    for(i = 0; i<n; i++){
	    a[i] *= a[i];
    }

    printf("The squared values of vector a are \n");
    for(i=0; i<n; i++){	
     	printf("%d ", a[i]);
    }
    printf("\n");
	
    //private copy of variable c in each process
    //variable c will be initialized to 0
    #pragma omp parallel for reduction (+:c)
    for(i=0; i<n; i++){
	     c += a[i] * b[n-i-1];
    }
    
    printf("The convolution of the two vectors is %d \n", c);
    return 0;
}
```


## Compute PI

$$
\int_{0}^1 \frac{4.0}{1+x^2} dx = \pi
$$

* Specify shared and private variable.
* Synchronization: 
	* ```pragma omp barrier```
	* ```pragma omp single```
	* ```pragma ordered```
	* ```pragma omp critical```
	* ```pragma omp atomic```

Only one thread at a time can enter a ```critical``` region.

```c
#include <omp.h>
#include <stdio.h>

int main(int argc, char ** argv){

    double x, sum, step, pi, aux;
    int i, num_steps;
    
    num_steps = 100000;
    x = 0.0;
    sum = 0.0;
    step = 1.0/(double) num_steps;
	#pragma omp parallel private(i,x,aux) shared(sum) 
    {
		aux = 0.0;
		#pragma omp for schedule(static) 
		for (i=0; i<num_steps; i=i+1){	    
		    x = (i+0.5)*step;
	   		 aux += 4.0/(1.0+x*x);
		}
	
		#pragma omp critical
		sum += aux;
   }
    
    pi=step*sum;

    printf("The result is %.20f \n", pi);
    return 0;
}
```
