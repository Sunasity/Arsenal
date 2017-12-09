#ifndef LINEAR_REGRESSION_H_
#define LINEAR_REGRESSION_H_


#include "Regression.hpp"
#include "Batch_Gradient_Descent.hpp"
//unfinished!!
namespace Arsenal{

template <typename Dtype>
//child class as linear regression
class Linear_Regression : public Regression<Dtype> {
public:
	Linear_Regression(){
	}

	Linear_Regression(Optim<Dtype> optim){
		_bgd._optim = optim;
	}


	Linear_Regression(int dimension, int Num_samples){
		this->_dimension = dimension;
		this->_Num_samples = Num_samples;
		this->weight.Shape_Init(this->_dimension, 1);
		this->bias.Shape_Init(1, 1);
		this->input.Shape_Init(this->_Num_samples, this->_dimension);
		this->output.Shape_Init(this->_Num_samples, 1);
		this->labels.Shape_Init(this->_Num_samples, 1);
		this->Weight_init();
	}


	void Forward();
	void Backward();
	void Test();
	void Train();
	void Dataset_get(Mat<Dtype> input_get, Mat<Dtype> labels_get);
private:
	Batch_Gradient_Descent<Dtype> _bgd;
};
	

}

#endif
