#include <stdio.h>
#include "Mat.hpp"

namespace Arsenal{
template <typename Dtype>
void MM_multiply_STRASSEN(const Dtype *A; const Dtype *B, Dtype *C, const int m, const int n, const int k){
	if ((m % 2 == 0) & (n % 2 == 0) & (k % 2 == 0)){
		int tmp_m = m / 2;
		int tmp_n = n / 2;
		int tmp_k = k / 2; 		
		Dtype *A11 = new Dtype(tmp_m * tmp_k);
		Dtype *A12 = new Dtype(tmp_m * tmp_k);
		Dtype *A21 = new Dtype(tmp_m * tmp_k);
		Dtype *A22 = new Dtype(tmp_m * tmp_k);
		Dtype *B11 = new Dtype(tmp_k * tmp_n);
		Dtype *B12 = new Dtype(tmp_k * tmp_n);
		Dtype *B21 = new Dtype(tmp_k * tmp_n);
		Dtype *B22 = new Dtype(tmp_k * tmp_n);
		Dtype *C11 = new Dtype(tmp_m * tmp_n);
		Dtype *C12 = new Dtype(tmp_m * tmp_n);
		Dtype *C21 = new Dtype(tmp_m * tmp_n);
		Dtype *C22 = new Dtype(tmp_m * tmp_n);

		Dtype *P1 = new Dtype(tmp_m * tmp_n);
		Dtype *P2 = new Dtype(tmp_m * tmp_n);
		Dtype *P3 = new Dtype(tmp_m * tmp_n);
		Dtype *P4 = new Dtype(tmp_m * tmp_n);
		Dtype *P5 = new Dtype(tmp_m * tmp_n);
		Dtype *P6 = new Dtype(tmp_m * tmp_n);
		Dtype *P7 = new Dtype(tmp_m * tmp_n);

		Dtype *P11 = new Dtype(tmp_k * tmp_n);
		Dtype *P20 = new Dtype(tmp_m * tmp_k);
		Dtype *P30 = new Dtype(tmp_m * tmp_k);
		Dtype *P41 = new Dtype(tmp_k * tmp_n);
		Dtype *P50 = new Dtype(tmp_m * tmp_k);
		Dtype *P51 = new Dtype(tmp_k * tmp_n);
		Dtype *P60 = new Dtype(tmp_m * tmp_k);
		Dtype *P61 = new Dtype(tmp_k * tmp_n);
		Dtype *P70 = new Dtype(tmp_m * tmp_k);
		Dtype *P71 = new Dtype(tmp_k * tmp_n);

		for (int i_tmp_m = 0; i_tmp_m < tmp_m; i_tmp_m ++){
			for (int i_tmp_k = 0; i_tmp_k < tmp_k; i_tmp_k ++){
				int IDX = tmp_k * i_tmp_m + i_tmp_k;
				int A11_idx = k * i_tmp_m + i_tmp_k;
				A11[IDX] = A[A11_idx];
				int A12_idx = k * i_tmp_m + i_tmp_k + tmp_k;
				A12[IDX] = A[A12_idx];
				int A21_idx = k * (i_tmp_m + tmp_m) + i_tmp_k;
				A21[IDX] = A[A21_idx];
				int A22_idx = k * (i_tmp_m + tmp_m) + i_tmp_k + tmp_k;
				A22[IDX] = A[A22_idx];
			}
		}

		for (int i_tmp_k = 0; i_tmp_k < tmp_k; i_tmp_k ++){
			for (int i_tmp_n = 0; i_tmp_n < tmp_n; i_tmp_n ++){
				int IDX = tmp_n * i_tmp_k + i_tmp_n;
				int B11_idx = n * i_tmp_k + i_tmp_n;
				B11[IDX] = B[B11_idx];
				int B12_idx = n * i_tmp_k + i_tmp_n + tmp_n;
				B12[IDX] = B[B12_idx];
				int B21_idx = n * (i_tmp_k + tmp_k) + i_tmp_n;
				B21[IDX] = B[B21_idx];
				int B22_idx = n * (i_tmp_k + tmp_k) + i_tmp_n + tmp_;
				B22[IDX] = B[B22_idx];
			}
		}

		MM_minus(B12, B22, P11, k, n);
		STRASSEN(A11, P11, P1, tmp_m, tmp_n, tmp_k);

		MM_add(A11, A12, P20, m, k);
		STRASSEN(P20, B22, P2, tmp_m, tmp_n, tmp_k);

		MM_add(A21, A22, P30, m, k);
		STRASSEN(P30, B11, P3, tmp_m, tmp_n, tmp_k);

		MM_minus(B21, B11, P41, k, n);
		STRASSEN(A22, P41, P4, tmp_m, tmp_n, tmp_k);

		MM_add(A11, A22, P50, m, k);
		MM_add(B11, B22, P51, k, n);
		STRASSEN(P50, P51, P5, tmp_m, tmp_n, tmp_k);

		MM_minus(A12, A22, P60, m, k);
		MM_add(B21, B22, P61, k, n);
		STRASSEN(P60, P61, P6, tmp_m, tmp_n, tmp_k);

		MM_minus(A11, A21, P70, m, k);
		MM_add(B11, B12, P71, k, n);
		STRASSEN(P70, P71, P7, tmp_m, tmp_n, tmp_k);
		

	}

	else{
	}
}	
}
