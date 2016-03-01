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
