#include "Mat.hpp"
#include "Regression.hpp"

namespace Arsenal{

template <typename Dtype>
//child class as linear regression
class Linear_Regression : public Regression{
	void Forward();
	void Backward();
	void Test();
	void Train();
}
}
