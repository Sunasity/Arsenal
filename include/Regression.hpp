#include "Mat.hpp"


namespace Arsenal{

template <typename Dtype>
//basis class for regression algorithm
class Regression{
public:
//+++++++++++++++++++++构造函数+++++++++++++++++++++++++++++
Regression(){
}
Regression(int _dimension, int _Num_smaples){
	dimension = _dimension;
	Num_samples = _Num_samples;
}
protected:
	void Weight_init();

	int dimension;
	int Num_samples;
	Mat weight(1, dimension);
	Mat input(Num_samples, dimension);
	Mat output(Num_samples);
}

}
