#include <string>
#include <fstream>

using std::string;
using std::ifstream;


namespace Arsenal{

template <typename Dtype>
class Mat{
public: 
	Mat(int row, int column){	//构造函数
		_row = row;
		_column = column;
		MAT_DATA = new Dtype[_row * _column];
	}

	Mat(int row, int column, string file_name){	//文件输入构造函数
		_row = row;
		_column = column;
		MAT_DATA = new Dtype[_row * _column];
		const char* _file_name = file_name.data();
		ifstream in_file(_file_name);
		for (int i = 0; i < _row * _column; i ++){
			in_file >> MAT_DATA[i];
		}
		//MAT_DATA = 
	}

	Mat(const Mat &src){		//拷贝构造函数
		_row = src._row;
		_column = src._column;
		MAT_DATA = new Dtype[_row * _column];
		for (int i = 0; i < _column; i ++){
			for (int j = 0; j < _row; j ++){
				int MAT_DATA_idx = j * _row + i;
				MAT_DATA[MAT_DATA_idx] = src.MAT_DATA[MAT_DATA_idx];
			}
		}
	} 

	~Mat(){		//析构函数
		delete []MAT_DATA;
	}
//++++++++++++++++++Mat_computation++++++++++++++++++++++++++++++++++++++++++
	void MM_multiply(const Mat &A, const Mat &B, Mat &C, const int m, const int n, const int k);   //C(m*n) = A(m*k) * B(k*n)矩阵乘法	
	void MV_multiply(bool TRANS, const Mat &A, const Mat &B, Mat &C, const int m, const int n);	
	//矩阵向量乘法 if(TRANS = false) C(m*1) = A(m*n) * B(n*1)
	//if(TRANS = true) C(1*m) = B(1*m) * A(m*n)

//++++++++++++++++++Mat_generate+++++++++++++++++++++++++++++++++++++++++++++
	void Zeros();
	void Ones();
	void Eye();
	void Random(const Dtype LowerBound, const Dtype UpperBound);	//产生均匀分布的随机阵
	void Randn(Dtype Average, Dtype Varience);
	void Randn_int(const int Average, const int Varience);   //产生int正态分布的随机阵
	void Randn_float(const float Average, const float Varience);	//产生float正态分布随机阵
	void Randn_double(const double Average, const double Varience);	  //禅城double正态分布随机阵	

//++++++++++++++++++Mat_shape_display+++++++++++++++++++++++++++++++++++++++++
	Dtype* GET_CPU_DATA();
	void Reshape();
	void Display();

private:
	void MM_multiply_STRASSEN(const Dtype *A, const Dtype *B, Dtype *C, const int m, const int n, const int k);	//STRASSEN矩阵算法
	void MM_add(Dtype *A, Dtype *B, Dtype *C, const int m, const int n);	//矩阵加法
	void MM_minus(Dtype *A, Dtype *B, Dtype *C, const int m, const int n);	//矩阵减法
	void MM_multiply_common(const Dtype *A, const Dtype *B, Dtype *C, const int m, const int n, const int k);	//普通矩阵乘法
	void MM_multiply_naive(const Dtype *A, const Dtype *B, Dtype *C, const int m, const int n, const int k);	//朴素矩阵乘法
	void MV_multiply_navie(bool TRANS, const Dtype *A, const Dtype *B, Dtype *C, const int m, const int n);		//朴素矩阵向量乘法
	Dtype *MAT_DATA;
	int _row, _column;

};

}
