#ifndef LINEAR_REGRESSION_H_
#define LINEAR_REGRESSION_H_


#include "Regression.hpp"


namespace Arsenal{

template <typename Dtype>
//child class as linear regression
class Linear_Regression : public Regression<Dtype> {
public:
	void Forward();
	void Backward();
	void Test();
	void Train();
};

}

#endif
