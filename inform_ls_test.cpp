#include <ap_int.h>

void lite_to_stream(ap_uint<15> inform_in, ap_uint<5> *inform1,
		ap_uint<5> *inform2, ap_uint<5> *inform3, ap_uint<5> *inform4,
		ap_uint<5> *inform5, ap_uint<5> *inform6, ap_uint<5> *inform7,
		ap_uint<5> *inform8, ap_uint<5> *inform9, ap_uint<5> *inform10,
		ap_uint<5> *inform11) ;

int main()
{
	ap_uint<15> inform_in ;
	ap_uint<5> inform1, inform2, inform3, inform4,
			   inform5, inform6, inform7, inform8,
			   inform9, inform10, inform11 ;

	inform_in = 0;
	lite_to_stream(inform_in, &inform1, &inform2, &inform3, &inform4,
					&inform5, &inform6, &inform7, &inform8,
					&inform9, &inform10, &inform11) ;
	printf("inform1 = %u\n",(unsigned int)inform1) ;
	printf("inform2 = %u\n",(unsigned int)inform2) ;
	printf("inform3 = %u\n",(unsigned int)inform3) ;
	printf("inform4 = %u\n",(unsigned int)inform4) ;
	printf("inform5 = %u\n",(unsigned int)inform5) ;
	printf("inform6 = %u\n",(unsigned int)inform6) ;
	printf("inform7 = %u\n",(unsigned int)inform7) ;
	printf("inform8 = %u\n",(unsigned int)inform8) ;
	printf("inform9 = %u\n",(unsigned int)inform9) ;
	printf("inform10 = %u\n",(unsigned int)inform10) ;
	printf("inform11 = %u\n\n",(unsigned int)inform11) ;

	inform_in = 32767 ;
	lite_to_stream(inform_in, &inform1, &inform2, &inform3, &inform4,
					&inform5, &inform6, &inform7, &inform8,
					&inform9, &inform10, &inform11) ;
	printf("inform1 = %u\n",(unsigned int)inform1) ;
	printf("inform2 = %u\n",(unsigned int)inform2) ;
	printf("inform3 = %u\n",(unsigned int)inform3) ;
	printf("inform4 = %u\n",(unsigned int)inform4) ;
	printf("inform5 = %u\n",(unsigned int)inform5) ;
	printf("inform6 = %u\n",(unsigned int)inform6) ;
	printf("inform7 = %u\n",(unsigned int)inform7) ;
	printf("inform8 = %u\n",(unsigned int)inform8) ;
	printf("inform9 = %u\n",(unsigned int)inform9) ;
	printf("inform10 = %u\n",(unsigned int)inform10) ;
	printf("inform11 = %u\n\n",(unsigned int)inform11) ;

	inform_in = 24576 ;
	lite_to_stream(inform_in, &inform1, &inform2, &inform3, &inform4,
					&inform5, &inform6, &inform7, &inform8,
					&inform9, &inform10, &inform11) ;
	printf("inform1 = %u\n",(unsigned int)inform1) ;
	printf("inform2 = %u\n",(unsigned int)inform2) ;
	printf("inform3 = %u\n",(unsigned int)inform3) ;
	printf("inform4 = %u\n",(unsigned int)inform4) ;
	printf("inform5 = %u\n",(unsigned int)inform5) ;
	printf("inform6 = %u\n",(unsigned int)inform6) ;
	printf("inform7 = %u\n",(unsigned int)inform7) ;
	printf("inform8 = %u\n",(unsigned int)inform8) ;
	printf("inform9 = %u\n",(unsigned int)inform9) ;
	printf("inform10 = %u\n",(unsigned int)inform10) ;
	printf("inform11 = %u\n\n",(unsigned int)inform11) ;

	inform_in = 4108 ;
	lite_to_stream(inform_in, &inform1, &inform2, &inform3, &inform4,
					&inform5, &inform6, &inform7, &inform8,
					&inform9, &inform10, &inform11) ;
	printf("inform1 = %u\n",(unsigned int)inform1) ;
	printf("inform2 = %u\n",(unsigned int)inform2) ;
	printf("inform3 = %u\n",(unsigned int)inform3) ;
	printf("inform4 = %u\n",(unsigned int)inform4) ;
	printf("inform5 = %u\n",(unsigned int)inform5) ;
	printf("inform6 = %u\n",(unsigned int)inform6) ;
	printf("inform7 = %u\n",(unsigned int)inform7) ;
	printf("inform8 = %u\n",(unsigned int)inform8) ;
	printf("inform9 = %u\n",(unsigned int)inform9) ;
	printf("inform10 = %u\n",(unsigned int)inform10) ;
	printf("inform11 = %u\n\n",(unsigned int)inform11) ;

	return 0 ;
}
