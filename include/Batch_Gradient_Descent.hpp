#ifndef BATCH_GRADIENT_DESCENT_H_
#define BATCH_GRADIENT_DESCENT_H_


#include "Mat.hpp"

namespace Arsenal{
template <typename Dtype>
class Optim{
public:
	float lr;
	float weight_decay;
	int max_epoch;
};


template <typename Dtype>
class Batch_Gradient_Descent{
public:
	Batch_Gradient_Descent(){
		_optim.lr = 0.05;
		_optim.weight_decay = 0;
		_optim.max_epoch = 0;
	}

	Batch_Gradient_Descent(Optim<Dtype> optim){
		_optim.lr = optim.lr;
		_optim.weight_decay = optim.weight_decay;
		_optim.max_epoch = optim.max_epoch;
	}

	void Linear_Regression_loss(Mat<Dtype> &labels, Mat<Dtype> &output);
	void Linear_Regression_bgd(Mat<Dtype> &labels, Mat<Dtype> &output, Mat<Dtype> &weight, Mat<Dtype> &bias, Mat<Dtype> &input);
private:
	Optim<Dtype> _optim;
	Dtype loss;
};

}

#endif
