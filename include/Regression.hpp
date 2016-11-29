#include "Mat.hpp"


namespace Arsenal{

template <typename Dtype>
//basis class for regression algorithm
class Regression{
public:
//+++++++++++++++++++++++++++++++++++++++++++++++++
	Regression(){
	}
	Regression(int _dimension, int _Num_smaples){
		dimension = _dimension;
		Num_samples = _Num_samples;
		Weight_init();
	}


	virtual void Forward();
	virtual void Backward();
	virtual void Test();
	virtual void Train();
protected:
	void Weight_init();

	int dimension;
	int Num_samples;
	Mat<Dtype> weight(dimension, 1);
	Mat<Dtype> bias;
	Mat<Dtype> input(Num_samples, dimension);
	Mat<Dtype> output(Num_samples);
}

}
