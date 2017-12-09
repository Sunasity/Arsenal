#include <stdio.h>
#include <iostream>
#include "../include/common.hpp"
#include <stdlib.h>
#include "../include/Regression.hpp"

using std::cout; using std::endl;

namespace Arsenal{
template <typename Dtype>
void Regression<Dtype>::Weight_init(){
	weight.Zeros();	
}


template <typename Dtype>
void Regression<Dtype>::Forward(){
}

template <typename Dtype>
void Regression<Dtype>::Backward(){
}

template <typename Dtype>
void Regression<Dtype>::Test(){
}

template <typename Dtype>
void Regression<Dtype>::Train(){
}

template <typename Dtype>
void Regression<Dtype>::Dataset_get(Mat<Dtype> input_get, Mat<Dtype> labels_get){	
	//input.Copy(input_get);
	//labels.Copy(labels_get);
}


INSTANCE_CLASS(Regression);
}
