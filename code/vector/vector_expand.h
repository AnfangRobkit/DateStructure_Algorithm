#pragma once
template <typename T> void Vector<T>::expand() {
//向量空间不足时进行扩容
	if (_size < _capacity) return; 
	if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
	T* oldElem = _elem;
	_elem = new T[_capacity << 1];//容量加倍
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}