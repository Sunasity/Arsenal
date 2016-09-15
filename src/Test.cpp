// Mat.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "Mat.hpp"
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#define TEST_TIME 1000
#define Mat_generate

using std::ofstream;
using std::string;
using std::endl;
using std::clock_t;
using std::cout;

using namespace Arsenal;

int main()
{

#ifdef Mat_computation
	clock_t start, end, inter;
	start = clock();
	int test_data[TEST_TIME];
	long long  average_data = 0;
	Mat<int> A(64,27, "../data/A_128x576.dat");
	Mat<int> B(27,224, "../data/B_576x224.dat");
	Mat<int> C(64, 224);	
	for (int i = 0; i < TEST_TIME; i ++){
		inter = clock();
		C.MM_multiply(A, B, C, 64, 224, 27);
		end = clock();
		test_data[i] = end - inter;
	}
	int *data_test = new int(64*224);
	data_test = C.GET_CPU_DATA();
	string file_name = "../data/C_128x224.dat";
	const char *_file_name = file_name.data();
	ofstream C_file(_file_name);
	for (int i = 0; i < 64*224; i ++){
		C_file << data_test[i] << endl;
	}
	cout << "Read_Time : " << test_data[0] - start << endl;
	for (int i = 0; i < TEST_TIME; i ++){
		average_data += test_data[i]; 
	}
	cout << "Average Time : " << average_data/TEST_TIME << endl;
#endif
	
#ifdef Mat_generate
	Mat<int> A(3,4);
	A.eye();
	int *b = A.GET_CPU_DATA();
	cout << b[0] << endl;
#endif
	return 0;
}




