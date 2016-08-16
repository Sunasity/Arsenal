#include <stdio.h>
#include "Mat.hpp"
#include "common.hpp"

#define NAIVE

namespace Arsenal{
template <typename Dtype>
void Mat<Dtype>::MM_multiply(const Mat &A, const Mat &B, Mat &C, const int m, const int n, const int k){

#ifdef NAIVE
	for (int i_m = 0; i_m < m; i_m ++){
		for (int i_n = 0; i_n < n; i_n ++){
			int C_idx = i_m * n + i_n;
			Dtype val = 0;
			for (int i_k = 0; i_k < k; i_k ++){
				int A_idx = i_m * k + i_k;
				int B_idx = i_k * n + i_n;
				val += A.MAT_DATA[A_idx] * B.MAT_DATA[B_idx];
			}
			C.MAT_DATA[C_idx] = val;
		}
	}
#endif

#ifdef ROW_DOMIN
	for (int i = 0; i < m * n; i ++){
		C.MAT_DATA[i] = 0;
	}

	for (int i_m = 0; i_m < m; i_m ++){   //from naive to row-domin
		for (int i_k = 0; i_k < k; i_k ++){
			int A_idx = i_m * k + i_k;
			if (A.MAT_DATA[A_idx]){			//剔除掉零元素
				for (int i_n = 0; i_n < n; i_n ++){
					int B_idx = i_k * n + i_n;
					int C_idx = i_m * n + i_n;
					C.MAT_DATA[C_idx] += A.MAT_DATA[A_idx] * B.MAT_DATA[B_idx];
				}
			}
		}
	}
#endif
}

template <typename Dtype>
Dtype* Mat<Dtype>::GET_CPU_DATA(){
	Dtype *CPU_DATA = new Dtype(_row * _column);
	CPU_DATA = MAT_DATA;
	return CPU_DATA;
}

INSTANCE_CLASS(Mat);
}
