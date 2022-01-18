#include<iostream>
#include"test.h"
#define COMMON_TEST 1
int main()
{

#ifdef COMMON_TEST
	radar_test();
#endif // COMMON_TEST
	return 0;
}