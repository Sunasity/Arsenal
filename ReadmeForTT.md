该代码用C++实现，用的是visual studio.所以Makefile写的不全，若使用请用VS2012及以上版本直接打开工程文件。

src：
	Mat：矩阵操作相关的函数(multi, reshape, transpose...)
	math_function：用于矩阵乘法的一些函数，可以不用管
	tt_fc_layer：基于tt的全连接层的计算
	Mat_test：主文件，修改tt的超参等都可以在此函数修改
	其他：其他的文件很久以前自己写着玩的...没什么用

include：
	对应的头文件
	
data:
	input.dat：input数据
	weight.dat/weight2.dat：一些weight数据
	均有python生成，很方便，不一定用包含的数据。
	
	