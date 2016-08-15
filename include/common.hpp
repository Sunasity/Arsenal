namespace Arsenal{

#define INSTANCE_CLASS(classname) \
	char gInstantiationGuard##classname; \
	template class classname<float>; \
	template class classname<double>; \
	template class classname<int> 
}