#include <stdio.h>
#include <iostream>
#include "Mat.hpp"
#include "common.hpp"
#include <stdlib.h>
#include "Linear_Regression.hpp"

namespace Arsenal{
template <typename Dtype>
void Linear_Regression<Dtype>::Forward(){
	output.MV_multiply(input, weight, output, Num_samples, dimension, 1);
}

template <typename Dtype>
void Linear_Regression<Dtype>::Test(){
	Forward();

}


INSTANCE_CLASS(Regression);
}
