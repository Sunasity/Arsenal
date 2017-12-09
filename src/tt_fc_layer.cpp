#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "../include/Mat.hpp"
#include "../include/tt_fc_layer.hpp"
#include "../include/common.hpp"

using std::cout;
using std::endl;

namespace Arsenal{

template <typename Dtype>
void tt_fc_layer<Dtype>::TT_layer(Mat<Dtype> &out, Mat<Dtype> &in, Mat<Dtype> &weight){
	Mat<Dtype> *_in = new Mat<Dtype>(in);	
	Mat<Dtype> *_weight = new Mat<Dtype>(weight);
	int *in_dim = new int[2];
	in_dim = _in[0].size();
	int in_total_dim = in_dim[0] * in_dim[1];		
	int in_size1 = _ranks[0]*_in_modes[0];
	int in_size2 = in_total_dim / (_ranks[0]*_in_modes[0]);

	_in[0].Reshape(in_size1, in_size2);
	
	int out_size1 = _ranks[1] * _out_modes[0];
	int weight_bias = 0;
		
	Mat<Dtype> *_weight_tmp = new Mat<Dtype>(_out_modes[0]*_ranks[1], _ranks[0]*_in_modes[0]);
	_weight_tmp[0].Copy(weight_bias, _weight[0]);

	Mat<Dtype> *_tmp = new Mat<Dtype>(out_size1, in_size2);
	_tmp[0].MM_multiply(_weight_tmp[0], _in[0], _tmp[0], out_size1, in_size2, in_size1);

	_tmp[0].Reshape(_out_modes[0], _ranks[1]*in_size2);
	_tmp[0].Transpose();


	for (int i = 1; i < _dim; i ++){			
		delete _in;

		_in = new Mat<Dtype>(_tmp[0]);
		delete _tmp;
		delete _weight_tmp;
		in_dim = _in[0].size();
		in_total_dim = in_dim[0] * in_dim[1];		
		in_size1 = _ranks[i]*_in_modes[i];
		in_size2 = in_total_dim / (_ranks[i]*_in_modes[i]);

		_in[0].Reshape(in_size1, in_size2);		
		out_size1 = _ranks[i+1] * _out_modes[i];
		
		
		weight_bias += _out_modes[i-1]*_ranks[i] * _ranks[i-1]*_in_modes[i-1];
		
		_weight_tmp = new Mat<Dtype>(_out_modes[i]*_ranks[i+1], _ranks[i]*_in_modes[i]);
		_weight_tmp[0].Copy(weight_bias, _weight[0]);
		_tmp = new Mat<Dtype>(out_size1, in_size2);

		_tmp[0].MM_multiply(_weight_tmp[0], _in[0], _tmp[0], out_size1, in_size2, in_size1);

		_tmp[0].Reshape(_out_modes[i], _ranks[i+1]*in_size2);
		_tmp[0].Transpose();
		
		if (i == _dim-1){
			out.Copy(_tmp[0]);
		}	
	}
}
INSTANCE_CLASS(tt_fc_layer);
}