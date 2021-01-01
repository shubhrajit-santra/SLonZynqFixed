#include <hls_math.h>
#include <math.h>
#include <ap_int.h>
#include <ap_fixed.h>

typedef ap_ufixed <18,3> fix ;
typedef ap_ufixed <16,1> fix2 ;
typedef ap_ufixed <19,4> fix3 ;
typedef ap_ufixed <29,14> wordN ;
typedef ap_ufixed <29,14> wordX ;
typedef ap_ufixed <3,1> fix1 ;

fix UCB(wordX X, ap_uint<14> T, wordN N){
	fix d, Q_in ;
	fix2 a ;
	fix3 b, c ;

		a = (fix2) (X/T) ;
		b = (fix3) hls::log(N) ;
		c = (fix3) (b/T) ;
		d = (fix) hls::sqrt(c) ;
		Q_in = (fix) (a + d) ;

		/*
		printf("\na = %f",(float)a) ;
		printf("\nb = %f",(float)b) ;
		printf("\nc = %f",(float)c) ;
		printf("\nd = %f",(float)d) ;
		printf("\nQ_in = %f\n",(float)Q_in) ;
		*/

	return Q_in;
}

// inform N_T_X_VACANT_ARMS
void machine(ap_uint<5> inform, fix *Q){
#pragma HLS INTERFACE axis register both port=Q
#pragma HLS INTERFACE axis register both port=inform

	static wordX X ;
	static ap_uint<14> T ;
	static wordN N ;

	fix1 reward ;
	ap_uint<3> vacant ;

	if(inform[0]==0){
		X = 1;
		T = 1;
		N = 11;
	}
	else{
		N += 1;

		if(inform[1]==1)
		{
			T += 1 ;
			vacant = (ap_uint<3>) inform.range(4,2);
			// reward = (float)((float)vacant/(float)4);

			if(vacant==0)
				reward = 0 ;
			else if(vacant==1)
				reward = 0.25 ;
			else if(vacant==2)
				reward = 0.5 ;
			else if(vacant==3)
				reward = 0.75 ;
			else if(vacant==4)
				reward = 1 ;

			X += reward;
		}
	}

	// printf("\nX = %f, T = %u, N = %u", (float)X, (unsigned int) T, (unsigned int) N) ;

	*Q = UCB(X, T, N);
}
