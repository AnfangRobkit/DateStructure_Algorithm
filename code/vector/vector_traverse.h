#pragma once
template <typename T>
void Vector<T>::traverse(void (*visit) (T&)){
	//借助函数指针机制
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}

template<typename T> template<typename VST>
void Vector<T>::traverse(VST& visit){
	//记住函数对象机制
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}
/*****************************************
*Usage: 统一将向量中所有元素加一
*1. 首先，实现一个可使得单个T类型元素加1的类
template <typename T>
struct Increase { //函数对象：通过重载()实现
	virtual void operator()(R &e) {e++;}
}
2. template <typename T>
void increase(Vector<T> &V) {
	V.travserse(Increase<T>());
}
******************************************/