#include <stdio.h>
#include <iostream>
#include "Mat.hpp"
#include "common.hpp"
#include <stdlib.h>

using std::cout; using std::endl;

namespace Arsenal{
template <typename Dtype>
void Weight_init(){
	weight.Zeors();	
}

INSTANCE_CLASS(Regression);
}
