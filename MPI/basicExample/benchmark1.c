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
