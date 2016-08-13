#include "Mat.hpp"

namespace Arsenal{
void Mat::MM_multiply(const Mat &A, const Mat &B, Mat &C, const int m, const int n, const int k){
	for (int i_m = 0; i_m < m; i_m ++){
		for (int i_n = 0; i_n < n; i_n ++){
			int C_idx = i_n * m + i_m;
			C[C_idx] = 0;
			for (int i_k = 0; i_k < k; i_k ++){
				int A_idx = i_k * m + i_m;
				int B_idx = i_n * k + i_k;
				C[C_idx] += A[A_idx] * B[B_idx];
			}
		}
	}
}
}
