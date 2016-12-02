#include <stdio.h>
#include <iostream>
#include "common.hpp"
#include <stdlib.h>
#include "Linear_Regression.hpp"

namespace Arsenal{
template <typename Dtype>
void Linear_Regression<Dtype>::Forward(){
	this->output.MV_multiply(false, this->input, this->weight, this->output, this->_Num_samples, this->_dimension);
	this->output.MM_add(this->output, this->bias, this->output);
}

template <typename Dtype>
void Linear_Regression<Dtype>::Test(){
	//int accu[3];
	Forward();
	//accu = this->output.Accuracy(this->output, this->labels);
}

template <typename Dtype>
void Linear_Regression<Dtype>::Backward(){
	//output.MV_multiply(input, weight, output, _Num_samples, _dimension, 1);
}

template <typename Dtype>
void Linear_Regression<Dtype>::Train(){
	Backward();
}

INSTANCE_CLASS(Linear_Regression);
}
