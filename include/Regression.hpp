#ifndef REGRESSION_H_
#define REGRESSION_H_


#include "Mat.hpp"

namespace Arsenal{

template <typename Dtype>
//basis class for regression algorithm
class Regression{
public:
	Regression(){
	}

	Regression(int dimension, int Num_samples){
		_dimension = dimension;
		_Num_samples = Num_samples;
		Mat<Dtype> weight(_dimension, 1);
		Mat<Dtype> bias(1, 1);
		Mat<Dtype> input(_Num_samples, _dimension);
		Mat<Dtype> output(_Num_samples, 1);
		Weight_init();
	}


	virtual void Forward();
	virtual void Backward();
	virtual void Test();
	virtual void Train();
protected:
	void Weight_init();

	int _dimension;
	int _Num_samples;
	Mat<Dtype> weight;
	Mat<Dtype> bias;
	Mat<Dtype> input;
	Mat<Dtype> output;
};



}

#endif
