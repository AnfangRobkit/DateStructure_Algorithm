#pragma once
template<typename T>
int Vector<T>::deduplicate() {
	// (无序向量)删除重复元素，并返回被删除元素数量
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
template <typename T>
int Vector<T>::uniquify() {
	//有序向量可以加速，因为其重复元素集中在一起，可以批量删除
	Rank i = 0, j = 0;
	while (++j < _size)
		if (_elem[i] != _elem[j])//else语句默认跳过雷同者
			_elem[i] = _elem[j];// 发现不同元素，向前移到紧邻于前者右侧
	_size = ++i;//隐式截取了尾部多余元素，没有进行一次remove操作
	shrink();
	return j - i;//返回向量规模变化量
}