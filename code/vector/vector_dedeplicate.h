#pragma once
template<typename T>
int Vector<T>::deduplicate() {
	//ɾ���ظ�Ԫ�أ������ر�ɾ��Ԫ������
	int oldSize = _size;
	Rank i = 1;
	while (i < _size)
	{
		if (find(_elem[i], 0, i) < 0)
			i++;
		else
			remove(i); //_size ��ʽ������remove������
	}
	return oldSize - _size;
}