//template <typename Dtype>
namespace Arsenal{

class Mat{
public: 
	Mat(int row, int column){	//构造函数
		_row = row;
		_column = column;
		MAT_DATA = new float[_row * _column];
		for (int i = 0; i < _column; i ++){
			for (int j = 0; j < row; j ++){
				int MAT_DATA_idx = j * _row + i;
				MAT_DATA[MAT_DATA_idx] = 0;
			}
		}
	}

	Mat(const Mat &src){		//拷贝构造函数
		_row = src._row;
		_column = src._column;
		MAT_DATA = new float[_row * _column];
		for (int i = 0; i < _column; i ++){
			for (int j = 0; j < _row; j ++){
				int MAT_DATA_idx = j * row + i;
				MAT_DATA[MAT_DATA_idx] = src.MAT_DATA[MAT_DATA_idx];
			}
		}
	} 

	~Mat(){		//析构函数
		delete [];
	}

	void MM_mutiply(const Mat &A, const Mat &B, Mat &C, const int m, const int n, const int k);   //C(m*n) = A(m*k) * B(k*n)


private:
	float *MAT_DATA;
	int _row, _column;

}


}
