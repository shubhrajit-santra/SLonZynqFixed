#include <stdio.h>
#include <ap_int.h>
#include <ap_fixed.h>

typedef ap_ufixed <18,3> fix ;

void machine(ap_uint<5> inform, fix *Q) ;

int main()
{
	fix Qval ;
	ap_uint<5> x ;
	ap_uint <1> t, n ;

	ap_uint<5> inform = 0 ;
 	machine(inform,&Qval) ;
 	printf("Simulation Output = %f\n",(float)Qval) ;

 	n = 1 ;
 	x = 0 ;
 	t = 0 ;
 	inform = (((x<<1)|t)<<1)|n ;
 	machine(inform,&Qval) ;
 	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 0 ;
 	t = 1 ;
 	inform = (((x<<1)|t)<<1)|n ;
 	machine(inform,&Qval) ;
 	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 0 ;
 	t = 0 ;
 	inform = (((x<<1)|t)<<1)|n ;
 	machine(inform,&Qval) ;
 	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 0 ;
 	t = 0 ;
 	inform = (((x<<1)|t)<<1)|n ;
 	machine(inform,&Qval) ;
 	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 2 ;
 	t = 1 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 0 ;
 	t = 0 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 3 ;
 	t = 1 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 4 ;
 	t = 1 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 0 ;
 	t = 0 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 0 ;
 	t = 0 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 0 ;
 	t = 1 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 0 ;
 	t = 0 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 0 ;
 	t = 0 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

 	x = 4 ;
 	t = 1 ;
 	inform = (((x<<1)|t)<<1)|n ;
	machine(inform,&Qval) ;
	printf("Simulation Output = %f\n",(float)Qval) ;

	printf("\nNo Error\n") ;

	return 0;
}
