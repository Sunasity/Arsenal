namespace Arsenal{
template <typename Dtype>
void MM_multiply_STRASSEN(const Dtype *A, const Dtype *B, Dtype *C, const int m, const int n, const int k);

template <typename Dtype>
void MM_add(Dtype *A, Dtype *B, Dtype *C, const int m, const int n);

template <typename Dtype>
void MM_minus(Dtype *A, Dtype *B, Dtype *C, const int m, const int n);

template <typename Dtype>
void MM_multiply(const Dtype *A, const Dtype *B, Dtype *C, const int m, const int n, const int k);

}
