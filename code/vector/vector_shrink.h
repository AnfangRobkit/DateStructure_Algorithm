#pragma once
template<typename T> void Vector<T>::shrink() { //装调因子过小时压缩向量所占空间
	if (_capacity < DEFAULT_CAPACITY << 1) return;
	if (_size << 2 > _capacity) return; //以25%为界限
	T* oldElem = _elem; _elem = new T[_capacity >>= 1]; //容量减半
	for (int i = 0; i < _size; i++) _elem[i] = oldElem[i];
	delete[] oldElem;//释放原空间
}