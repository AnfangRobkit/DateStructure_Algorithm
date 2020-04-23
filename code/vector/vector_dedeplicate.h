#pragma once
template<typename T>
int Vector<T>::deduplicate() {
	// (��������)ɾ���ظ�Ԫ�أ������ر�ɾ��Ԫ������
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
template <typename T>
int Vector<T>::uniquify() {
	//�����������Լ��٣���Ϊ���ظ�Ԫ�ؼ�����һ�𣬿�������ɾ��
	Rank i = 0, j = 0;
	while (++j < _size)
		if (_elem[i] != _elem[j])//else���Ĭ��������ͬ��
			_elem[i] = _elem[j];// ���ֲ�ͬԪ�أ���ǰ�Ƶ�������ǰ���Ҳ�
	_size = ++i;//��ʽ��ȡ��β������Ԫ�أ�û�н���һ��remove����
	shrink();
	return j - i;//����������ģ�仯��
}