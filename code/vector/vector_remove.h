#pragma once
template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
// 删除区间[lo, hi)，返回被删除元素的数目
	if (lo == hi) return 0;
	while (hi<_siz)
	{
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;
	shrink();
	return (hi - lo);
}

template <typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}