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
