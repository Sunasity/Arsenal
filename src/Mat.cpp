#include <stdio.h>
#include "Mat.hpp"
#include "common.hpp"

#define TILING_SIZE
#define FOLDING_SIZE 16
#define PE C.MAT_DATA[C_idx] += tmp * B.MAT_DATA[B_idx]; \
		   B_idx ++; \
		   C_idx ++;

#define PU for (int i_para = 0; i_para < n / FOLDING_SIZE; i_para ++){ \
			   C.MAT_DATA[C_idx] += tmp * B.MAT_DATA[B_idx]; \
			   B_idx ++; \
			   C_idx ++;}																

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
	
	//Dtype *p_b;
	//Dtype *p_c;
	for (int i_m = 0; i_m < m; i_m ++){   //from naive to row-domin
		for (int i_k = 0; i_k < k; i_k ++){
			int A_idx = i_m * k + i_k;
			Dtype tmp = A.MAT_DATA[A_idx];
			int B_idx = i_k * n; int C_idx = i_m * n;
#if 1		
			if (tmp){	
				for (int i_n = 0; i_n <= (n / FOLDING_SIZE); i_n ++){
					if (i_n   < (n / FOLDING_SIZE)){						
						PE; PE; PE; PE;
						PE; PE; PE; PE;
						PE; PE; PE; PE;
						PE; PE; PE; PE;
					}
					else{
						for (int i_para = 0; i_para < n % FOLDING_SIZE; i_para ++){
							C.MAT_DATA[C_idx] += tmp * B.MAT_DATA[B_idx];						
							B_idx ++;
							C_idx ++;
						}
					}				
				}
			}
#endif
#if 0
			PU; PU; PU; PU; 
			PU; PU; PU; PU; 
			PU; PU; PU; PU; 
			PU; PU; PU; PU; 

			for (int i_para = 0; i_para < n % FOLDING_SIZE; i_para ++){
				C.MAT_DATA[C_idx] += tmp * B.MAT_DATA[B_idx];						
				B_idx ++;
				C_idx ++;
			}
#endif
		}
	}
#endif


#ifdef TILING_SIZE
	const int T = 8;

	for (int i = 0; i < m * n; i ++){
		C.MAT_DATA[i] = 1;
	}

	for (int it_m = 0; it_m < m; it_m += T){
		for (int it_n = 0; it_n < n; it_n += T){
			for (int it_k = 0; it_k < k; it_k += T){
				for (int i_m = it_m; i_m < it_m + T; i_m ++){
					for (int i_n = it_n; i_n < it_n + T; i_n ++){
						int C_idx = i_m * n + i_n;
						for (int i_k = it_k; i_k < it_k + T; i_k ++){
							int A_idx = i_m * k + i_k;
							int B_idx = i_k * n + i_n;
							C.MAT_DATA[C_idx] += A.MAT_DATA[A_idx] * B.MAT_DATA[B_idx];
						}
					}
				}
			}
		}
	}
#endif

#ifdef STRASSEN

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
