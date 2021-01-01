
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

#include "xlite_to_stream.h"
#include "xCompare.h"

XLite_to_stream ls ;
XCompare compare;

int ls_init(XLite_to_stream *ptr){

	XLite_to_stream_Config *cfgPtr;
    int status;

    cfgPtr = XLite_to_stream_LookupConfig(XPAR_LITE_TO_STREAM_DEVICE_ID);
    if (!cfgPtr) {
        print("ERROR: Lookup failed.\n\r");
        return XST_FAILURE;
    }

    status = XLite_to_stream_CfgInitialize(ptr, cfgPtr);
    if (status != XST_SUCCESS) {
        print("ERROR: Could not initialize.\n\r");
        return XST_FAILURE;
    }

    return status;
}

int compare_init(XCompare *ptr){

	XCompare_Config *cfgPtr;
    int status;

    cfgPtr = XCompare_LookupConfig(XPAR_COMPARE_DEVICE_ID);
    if (!cfgPtr) {
        print("ERROR: Lookup failed.\n\r");
        return XST_FAILURE;
    }

    status = XCompare_CfgInitialize(ptr, cfgPtr);
    if (status != XST_SUCCESS) {
        print("ERROR: Could not initialize.\n\r");
        return XST_FAILURE;
    }

    return status;
}

void runAlgorithm();

int main()
{
    init_platform();

    int status;

    status = compare_init(&compare);
    status = ls_init(&ls);

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
	 float pr[11] ;

    float x[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned int t[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned int n = 0;

    unsigned int subset[] = {3,5,6,7,9,10,11,12,13,14,15};
    unsigned int K = 2;

    unsigned int selected, arms, vacant, subset_val, tau = 0;
    double r = 0;

    uint32_t inform = 0 ;

	XLite_to_stream_Set_inform_in_V(&ls,inform) ;

    XTime tprocessorStart, tprocessorEnd ;
	XTime_GetTime(&tprocessorStart);

    for(int i=1; i<=10000;i++){

    	// usleep(100);

    	if(i<=11)
    		selected = i+1 ;
    	else
    		selected = XCompare_Get_maxQ_V(&compare) ;

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
        		if(r < probs[j])
        			vacant++;
        	}
        }
        if((arms-vacant) > K)
        	vacant = 0 ;

        tau += vacant ;

		inform = (((vacant<<11) | (1<<selected))<<1)|1 ;
		XLite_to_stream_Set_inform_in_V(&ls,inform) ;

    	x[selected] += (float)vacant/4;
		t[selected] += 1;
    	n += 1;
    }

    XTime_GetTime(&tprocessorEnd);

    for(int k = 0 ; k < 11 ; k++ )
    {
    	printf("X[%d] = %0.4f		T[%d] = %u \r\n", k, x[k], k, t[k]) ;

		pr[k] = x[k]/t[k] ;
    }

    printf("N = %u \r\n", n) ;

    float temp ;
    unsigned int temp1 ;

    for( int p = 0 ; p < 10 ; p++ )
    {
    	for( int q = 0 ; q < 10-p ; q++ )
    	{
    		if(pr[q]<pr[q+1])
    		{
    			temp = pr[q] ;
				pr[q] = pr[q+1] ;
				pr[q+1] = temp ;

				temp1 = subset[q] ;
				subset[q] = subset[q+1] ;
				subset[q+1] = temp1 ;
    		}
    	}
    }

    subset_val = subset[0] ;

    printf("Optimal Subset is: {") ;

    for( int l = 0; l < 4 ; l++ )
    {
	if((subset_val>>l)&1)
            printf(" %d",l+1) ;
    }
    printf(" }\n") ;

    printf("Best Subsets Ranking:\n") ;

    for(int r=0;r<11;r++)
    {
    	printf("{") ;
    	for( int t = 0; t < 4 ; t++ )
		{
    		if((subset[r]>>t)&1)
				printf(" %d",t+1) ;
		}
    	printf(" }\n") ;
    }

    printf("\nTotal Reward: %u",tau) ;

    printf("\nPS took %.2f us.\n\n", 1.0 * (tprocessorEnd - tprocessorStart) / (COUNTS_PER_SECOND/1000000));

}
