#pragma once
template <typename T>
void Vector<T>::traverse(void (*visit) (T&)){
	//��������ָ�����
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}

template<typename T> template<typename VST>
void Vector<T>::traverse(VST& visit){
	//��ס�����������
	for (int i = 0; i < _size; i++)
		visit(_elem[i]);
}
/*****************************************
*Usage: ͳһ������������Ԫ�ؼ�һ
*1. ���ȣ�ʵ��һ����ʹ�õ���T����Ԫ�ؼ�1����
template <typename T>
struct Increase { //��������ͨ������()ʵ��
	virtual void operator()(R &e) {e++;}
}
2. template <typename T>
void increase(Vector<T> &V) {
	V.travserse(Increase<T>());
}
******************************************/