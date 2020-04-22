#pragma once
template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	for (int i = _size; i > r; i--)
		_elem[i] = _elem[i - 1];
	// i = _size, 已经隐含多向后shift一个单元的含义
	_elem[r] = e;
	_size++;
	return r;
}