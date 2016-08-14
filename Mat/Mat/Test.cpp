// Mat.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Mat.hpp"
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>

using std::ofstream;
using std::string;
using std::endl;
using std::clock_t;
using std::cout;

using namespace Arsenal;

int _tmain(int argc, _TCHAR* argv[])
{

	clock_t start, end, inter;
	start = clock();
	Mat<int> A(64,27, "A_64x27.dat");
	Mat<int> B(27,224, "B_27x224.dat");
	Mat<int> C(64, 224);	
	inter = clock();

	C.MM_multiply(A, B, C, 64, 224, 27);
	end = clock();
	int *data_test = new int(64*224);
	data_test = C.GET_CPU_DATA();
	string file_name = "C_64x224.dat";
	const char *_file_name = file_name.data();
	ofstream C_file(_file_name);
	for (int i = 0; i < 64*224; i ++){
		C_file << data_test[i] << endl;
	}
	cout << "Read_Time : " << inter - start << endl;
	cout << "Compute_Time : " << end - inter << endl;

	return 0;
}

