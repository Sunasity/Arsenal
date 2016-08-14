#include <string>
#include <fstream>

using std::string;
using std::ifstream;


namespace Arsenal{

template <typename Dtype>
class Mat{
public: 
	inline Mat(int row, int column){	//构造函数
		_row = row;
		_column = column;
		MAT_DATA = new Dtype[_row * _column];
		for (int i = 0; i < _column; i ++){
			for (int j = 0; j < _row; j ++){
				int MAT_DATA_idx = j * _row + i;
				MAT_DATA[MAT_DATA_idx] = 0;
			}
		}
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

	void MM_multiply(const Mat &A, const Mat &B, Mat &C, const int m, const int n, const int k);   //C(m*n) = A(m*k) * B(k*n)矩阵乘法	
	Dtype* GET_CPU_DATA();

private:
	Dtype *MAT_DATA;
	int _row, _column;

};


}
