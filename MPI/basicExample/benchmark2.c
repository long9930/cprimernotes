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
