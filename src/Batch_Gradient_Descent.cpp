#include <stdio.h>
#include <iostream>
#include "../include/common.hpp"
#include "../include/Batch_Gradient_Descent.hpp"

using std::cout; using std::endl;

namespace Arsenal{
template <typename Dtype>
void Batch_Gradient_Descent<Dtype>::Linear_Regression_loss(Mat<Dtype> &labels, Mat<Dtype> &output){
	int* size = new int(2);
	size = labels.size();
	Mat<Dtype> Err_vec(size[0], size[1]);

	Err_vec.MM_sub(labels, output, Err_vec);	
	Err_vec.Dot(Err_vec, Err_vec, Err_vec);
	Err_vec.bias_division(Err_vec, 2, Err_vec);
	loss = Err_vec.Sum();
}

template <typename Dtype>
void Batch_Gradient_Descent<Dtype>::Linear_Regression_bgd(Mat<Dtype> &labels, Mat<Dtype> &output, Mat<Dtype> & weight, Mat<Dtype> &bias, Mat<Dtype> &input){
	int* size_grad = new int(2);
	int* size_err = new int(2);
	size_grad = weight.size();
	size_err = labels.size();
	const int dimension = size_grad[0];
	const int Num_samples = size_err[0];
	Mat<Dtype> Gradient(size_grad[0], size_grad[1]);
	Mat<Dtype> Err_vec(size_err[0], size_err[1]);
	Mat<Dtype> Grad(1, 1);

	output.MV_multiply(false, input, weight, output, Num_samples, dimension);
	output.MM_add(output, bias, output);
	Linear_Regression_loss(labels, output);
	Dtype loss_last = loss + 1;
	cout << "loss:" << loss - 1 << endl;


	if (!_optim.max_epoch){
		while (loss_last <= loss){
			loss_last = loss;
			output.MV_multiply(false, input, weight, output, Num_samples, dimension);
			output.MM_add(output, bias, output);
			Err_vec.MM_sub(labels, output, Err_vec);
			input.Transpose();
			Gradient.MV_multiply(false, input, Err_vec, Gradient, dimension, Num_samples);
			Gradient.bias_division(Gradient, Num_samples, Gradient);
			Gradient.bias_multiply(Gradient, _optim.lr, Gradient);
			weight.bias_multiply(weight, 1 - _optim.lr * _optim.weight_decay / Num_samples, weight);
			weight.MM_sub(weight, Gradient, weight);
			input.Transpose();			

//test of loss
			output.MV_multiply(false, input, weight, output, Num_samples, dimension);
			output.MM_add(output, bias, output);
			Linear_Regression_loss(labels, output);
			cout << "loss:" << loss << endl;
		}
	}else
	{
		for (int iter = 0; iter < _optim.max_epoch; iter ++){
//gradient descent
			cout << "Epoch " << iter << ":" << endl;
			output.MV_multiply(false, input, weight, output, Num_samples, dimension);
			output.MM_add(output, bias, output);
			Err_vec.MM_sub(labels, output, Err_vec);
			input.Transpose();
			Gradient.MV_multiply(false, input, Err_vec, Gradient, dimension, Num_samples);
			Gradient.bias_division(Gradient, Num_samples, Gradient);
			Gradient.bias_multiply(Gradient, _optim.lr, Gradient);
			weight.bias_multiply(weight, 1 - _optim.lr * _optim.weight_decay / Num_samples, weight);
			weight.MM_sub(weight, Gradient, weight);
			input.Transpose();			
//test of loss
			output.MV_multiply(false, input, weight, output, Num_samples, dimension);
			output.MM_add(output, bias, output);
			Linear_Regression_loss(labels, output);
			cout << "loss:" << loss << endl;
		}
	}
}


INSTANCE_CLASS(Batch_Gradient_Descent);
}
