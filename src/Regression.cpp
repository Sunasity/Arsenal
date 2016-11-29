#include <stdio.h>
#include <iostream>
#include "Mat.hpp"
#include "common.hpp"
#include <stdlib.h>
#include "Regression.hpp"

using std::cout; using std::endl;

namespace Arsenal{
template <typename Dtype>
void Regression<Dtype>::Weight_init(){
	weight.Zeors();	
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

INSTANCE_CLASS(Regression);
}
