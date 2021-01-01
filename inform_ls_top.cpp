#include <ap_int.h>

void lite_to_stream(ap_uint<15> inform_in, ap_uint<5> *inform1,
		ap_uint<5> *inform2, ap_uint<5> *inform3, ap_uint<5> *inform4,
		ap_uint<5> *inform5, ap_uint<5> *inform6, ap_uint<5> *inform7,
		ap_uint<5> *inform8, ap_uint<5> *inform9, ap_uint<5> *inform10,
		ap_uint<5> *inform11)
{
#pragma HLS INTERFACE s_axilite port=inform_in
#pragma HLS INTERFACE axis register both port=inform1
#pragma HLS INTERFACE axis register both port=inform2
#pragma HLS INTERFACE axis register both port=inform3
#pragma HLS INTERFACE axis register both port=inform4
#pragma HLS INTERFACE axis register both port=inform5
#pragma HLS INTERFACE axis register both port=inform6
#pragma HLS INTERFACE axis register both port=inform7
#pragma HLS INTERFACE axis register both port=inform8
#pragma HLS INTERFACE axis register both port=inform9
#pragma HLS INTERFACE axis register both port=inform10
#pragma HLS INTERFACE axis register both port=inform11

	ap_uint <5> inform_temp1, inform_temp2, inform_temp3, inform_temp4,
				inform_temp5, inform_temp6, inform_temp7, inform_temp8,
				inform_temp9, inform_temp10, inform_temp11 ;

	inform_temp1 = (((inform_in.range(14,12)<<1) | inform_in[1])<<1) | inform_in[0] ;
	inform_temp2 = (((inform_in.range(14,12)<<1) | inform_in[2])<<1) | inform_in[0] ;
	inform_temp3 = (((inform_in.range(14,12)<<1) | inform_in[3])<<1) | inform_in[0] ;
	inform_temp4 = (((inform_in.range(14,12)<<1) | inform_in[4])<<1) | inform_in[0] ;
	inform_temp5 = (((inform_in.range(14,12)<<1) | inform_in[5])<<1) | inform_in[0] ;
	inform_temp6 = (((inform_in.range(14,12)<<1) | inform_in[6])<<1) | inform_in[0] ;
	inform_temp7 = (((inform_in.range(14,12)<<1) | inform_in[7])<<1) | inform_in[0] ;
	inform_temp8 = (((inform_in.range(14,12)<<1) | inform_in[8])<<1) | inform_in[0] ;
	inform_temp9 = (((inform_in.range(14,12)<<1) | inform_in[9])<<1) | inform_in[0] ;
	inform_temp10 = (((inform_in.range(14,12)<<1) | inform_in[10])<<1) | inform_in[0] ;
	inform_temp11 = (((inform_in.range(14,12)<<1) | inform_in[11])<<1) | inform_in[0] ;

	*inform1 = inform_temp1 ;
	*inform2 = inform_temp2 ;
	*inform3 = inform_temp3 ;
	*inform4 = inform_temp4 ;
	*inform5 = inform_temp5 ;
	*inform6 = inform_temp6 ;
	*inform7 = inform_temp7 ;
	*inform8 = inform_temp8 ;
	*inform9 = inform_temp9 ;
	*inform10 = inform_temp10 ;
	*inform11 = inform_temp11 ;
}
