
/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "math.h"
#include <time.h>
#include <stdlib.h>
#include "xil_cache.h"
#include "xil_types.h"
#include "xtime_l.h"
#include <sleep.h>

void runAlgorithm();

int main()
{
    init_platform();

    runAlgorithm();

    cleanup_platform();
    return 0;
}

void runAlgorithm(){

    // double probs[] = {0.3, 0.0, 0.7, 0.1};
    // double probs[] = {0.4, 0.9, 0.6, 0.7};
	 double probs[] = {0.1, 0.3, 0.5, 0.7} ;
	// double probs[] = {0.51, 0.52, 0.53, 0.54} ;
	// double probs[] = {0.11, 0.21, 0.31, 0.41} ;
	// double probs[] = {0.38, 0.24, 0.77, 0.65} ;

    double x[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ;
    unsigned int t[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ;
    unsigned int n = 11 ;

    unsigned int subset[] = {3,5,6,7,9,10,11,12,13,14,15};
    unsigned int K = 2;
    float Q[11], maxQ ;

    unsigned int selected, arms, vacant, subset_val, tau = 0 ;
    double r = 0;

    XTime tprocessorStart, tprocessorEnd ;
	XTime_GetTime(&tprocessorStart);

    for(int i=1; i<=10000;i++){

    	// usleep(100);

    	if(i<=11)
    		selected = i;
    	else
    	{
    		maxQ = -1 ;
			for(int k = 0 ; k<11 ;k++)
			{
				Q[k] = (float)x[k]/(float)t[k] + (float)sqrt(((float)log(n))/(float)t[k]) ;

				if(Q[k]>maxQ)
				{
					maxQ = Q[k] ;
					selected = k+1 ;
				}
			}
    	}

    	// printf("sel = %u \r\n",selected) ;

    	selected-- ;

    	subset_val = subset[selected];

    	r = (double) rand()/ (double) RAND_MAX;
    	// r = 0.5 ;

        arms = 0;
        vacant = 0;
        for(int j = 0 ; j < 4 ; j++){
        	if((subset_val>>j)&1){
        		arms++;
        		if(r < probs[3-j])
        			vacant++;
        	}
        }
        if((arms-vacant) > K)
        	vacant = 0 ;

        tau += vacant ;

    	x[selected] += (float)vacant/(float)4;
		t[selected] += 1;
    	n += 1;
    }

    XTime_GetTime(&tprocessorEnd);

    unsigned int max = 0;
    int index ;

    for(int k = 0 ; k < 11 ; k++ )
    {
    	printf("X[%d] = %0.4f		T[%d] = %u \r\n", k, x[k]-1, k, t[k]-1) ;

		if(t[k]>max)
		{
			max = t[k] ;
			index = k ;
		}
    }

    printf("N = %u \r\n", n-11) ;

    subset_val = subset[index] ;

    printf("Optimal Subset is: {") ;

    for( int l = 0; l < 4 ; l++ )
    {
	if((subset_val>>(3-l))&1)
            printf(" %d",l+1) ;
    }

    printf(" }\n") ;

    float temp ;
    unsigned int temp1 ;

    for( int p = 0 ; p < 10 ; p++ )
    {
    	for( int q = 0 ; q < 10-p ; q++ )
    	{
    		if(x[q]<x[q+1])
    		{
    			temp = x[q] ;
				x[q] = x[q+1] ;
				x[q+1] = temp ;

				temp1 = subset[q] ;
				subset[q] = subset[q+1] ;
				subset[q+1] = temp1 ;
    		}
    	}
    }

    printf("Best Subsets Ranking:\n") ;

    for(int r=0;r<11;r++)
    {
    	printf("{") ;
    	for( int t = 0; t < 4 ; t++ )
		{
    		if((subset[r]>>(3-t))&1)
				printf(" %d",t+1) ;
		}
    	printf(" }\n") ;
    }

    printf("\nTotal Reward: %u",tau) ;

    printf("\nPS took %.2f us.\n\n", 1.0 * (tprocessorEnd - tprocessorStart) / (COUNTS_PER_SECOND/1000000));

}
