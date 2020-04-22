#pragma once
template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	for (int i = _size; i > r; i--)
		_elem[i] = _elem[i - 1];
	// i = _size, �Ѿ����������shiftһ����Ԫ�ĺ���
	_elem[r] = e;
	_size++;
	return r;
}