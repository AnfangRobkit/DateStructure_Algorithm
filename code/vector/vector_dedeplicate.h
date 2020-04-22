#pragma once
template<typename T>
int Vector<T>::deduplicate() {
	//删除重复元素，并返回被删除元素数量
	int oldSize = _size;
	Rank i = 1;
	while (i < _size)
	{
		if (find(_elem[i], 0, i) < 0)
			i++;
		else
			remove(i); //_size 隐式更新在remove操作里
	}
	return oldSize - _size;
}