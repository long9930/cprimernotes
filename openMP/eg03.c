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
