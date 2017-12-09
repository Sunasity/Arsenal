#ifndef TT_FC_LAYER_H_
#define TT_FC_LAYER_H_
#include "Mat.hpp"
#include <iostream>

using std::cout;
using std::endl;

namespace Arsenal{

template <typename Dtype>
class tt_fc_layer{
public:
	tt_fc_layer(int dim, int in_shape, int out_shape, int *in_modes, int *out_modes, int *ranks){
		_dim = dim;
		_in_shape = in_shape;
		_out_shape = out_shape;
		_weight_shape = 0;
		_in_modes = new int[_dim];
		_out_modes = new int[_dim];
		_ranks = new int[_dim+1];


		int in_shape_test = 1;
		int out_shape_test = 1;
		for (int i = 0; i < _dim; i ++){
			_in_modes[i] = in_modes[i];
			_out_modes[i] = out_modes[i];
			in_shape_test *= in_modes[i];
			out_shape_test *= out_modes[i];
		}
		if ((in_shape_test != _in_shape) | (out_shape_test != _out_shape)){
			cout << "Error: shape must be equal!" << endl;
		}


		for (int i = 0; i <= _dim; i ++){
			_ranks[i] = ranks[i];
		}		
		for (int i = 0; i < _dim; i ++){
			_weight_shape += (_out_modes[i]*_ranks[i+1]) * (_ranks[i]*_in_modes[i]);
		}

		//_weight = new Dtype[_weight_shape];
		//_input = new Dtype[_input_shape];
		//_output = new Dtype[_output_shape];		
	}
	~tt_fc_layer(){
		delete []_in_modes;
		delete []_out_modes;
		delete []_ranks;
	}

	//void data_init(Dtype *weight, Dtype *input, Dtype *output);
	//void data_init();
	void TT_layer(Mat<Dtype> &out, Mat<Dtype> &in, Mat<Dtype> &weight);

private:
	//hps-------------------------
	int _dim;
	int *_in_modes;
	int *_out_modes;
	int *_ranks;
	int _in_shape;
	int _out_shape;
	int _weight_shape;

	//data-------------------------
	//Mat *_weight;
	//Mat *_input;
	//Mat *_output;
};
}
#endif