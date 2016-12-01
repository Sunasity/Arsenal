#ifndef LINEAR_REGRESSION_H_
#define LINEAR_REGRESSION_H_


#include "Regression.hpp"

namespace Arsenal{

template <typename Dtype>
//child class as linear regression
class Linear_Regression : public Regression<Dtype> {
public:
	Linear_Regression(){
	}

	Linear_Regression(int dimension, int Num_samples){
		this->_dimension = dimension;
		this->_Num_samples = Num_samples;
		//Mat<Dtype> weight(_dimension, 1);
		//Mat<Dtype> bias(1, 1);
		//Mat<Dtype> input(_Num_samples, _dimension);
		//Mat<Dtype> output(_Num_samples, 1);
		this->Weight_init();
	}

	void Forward();
	void Backward();
	void Test();
	void Train();
};

}

#endif
