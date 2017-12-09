// Mat.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include "../include/Mat.hpp"
#include "../include/tt_fc_layer.hpp"
#include <fstream>
#include <string>
#include <ctime>
#include <iostream>
#define TEST_TIME 1000

using std::ofstream;
using std::ifstream;
using std::string;
using std::endl;
using std::cout;

using namespace Arsenal;

int main()
{
	int in_modes[6] = {4,4,4,4,4,3};
	int ranks[7] = {1,3,3,3,3,3,1};
	int out_modes[6] = {8,8,8,8,8,8};
	int dim = 6;
	int in_shape = 3072;
	int out_shape = 262144;
	string input_file = "./data/input.dat";
	string weight_file = "./data/weight.dat";




	Mat<float> input(in_shape, 1, input_file);
	Mat<float> weight(1320, 1, weight_file);
	Mat<float> output(out_shape, 1);
	tt_fc_layer<float> tt(dim, in_shape, out_shape, in_modes, out_modes, ranks);
	tt.TT_layer(output, input, weight);
	output.Display();



	
	
	system("pause");
	return 0;
}




