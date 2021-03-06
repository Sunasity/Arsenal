#ifndef REGRESSION_H_
#define REGRESSION_H_


#include "Mat.hpp"
//unfinished!!
namespace Arsenal{

template <typename Dtype>
//basis class for regression algorithm
class Regression{
public:
	Regression(){
	}


	virtual void Forward();
	virtual void Backward();
	virtual void Test();
	virtual void Train();

	void Dataset_get(Mat<Dtype> input_get, Mat<Dtype> labels_get);

protected:
	void Weight_init();
	int _dimension;
	int _Num_samples;
	Mat<Dtype> weight;
	Mat<Dtype> bias;
	Mat<Dtype> input;
	Mat<Dtype> output;
	Mat<Dtype> labels;

};



}

#endif
