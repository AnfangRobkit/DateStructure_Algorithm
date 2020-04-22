#pragma once

typedef int Rank; //��
#define DEFAULT_CAPACITY 3 //Ĭ�ϳ�ʼ����Ϊ3

template<typename T> class  Vector
{

protected:
	Rank _size;
	int _capacity;
	T* _elem; //��ģ ���� ������
	void copyFrom(T const* A, Rank lo, Rank hi); // ������������
	void expand();//�ռ䲻��ʱ��������
	void shrink();//װ�����ӹ�Сʱѹ��
	bool bubble(Rank lo, Rank hi);//ɨ�轻��
	void bublleSort(Rank lo, Rank hi);
	Rank max(Rank lo, Rank hi);//ѡȡ���Ԫ��
	void selectSort(Rank lo, Rank hi);//ѡ�������㷨
	void merge(Rank lo, Rank mi, Rank hi); //�鲢����
	void mergeSort(Rank lo, Rank hi);// �鲢�����㷨

public:
	// ���캯��
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) // ����Ϊc ��ģΪs ����Ԫ�س�ʼΪv
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); } //�������帴��
	Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //�������临��
	Vector(Vector<T>const& V) { copyFrom(V._elem, 0, V._size); } //�������帴��
	Vector(Vector<T>const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } // �������临��
	// ��������
	~Vector() { delete[]_elem; }
	// ֻ�����ʽӿ�
	Rank size() const { return _size; } //�ຯ����Ա����Ϊconst �Ա����䲻���޸������
	bool empty() const { return !_size; }
	Rank find(T const& e, Rank lo, Rank hi) const; //���������������
	Rank search(T const& e) const {
		return (0 >= _size) ? -1 : search(e, 0, _size);
	}
	//��д���ʽӿ�
	T& operator[] (Rank r); //�����±���������������������ʽ���ø�Ԫ��
	const T& operator[] (Rank r) const; //����������ֵ�����ذ汾
	Vector<T>& operator= (Vector<T>const&); //��¡����
	T remove(Rank r);//ɾ����Ϊr��Ԫ��
	int remove(Rank lo, Rank hi); //ɾ������Ԫ��
	Rank insert(Rank r, T const& e); //����Ԫ��
	Rank insert(T const& e) { return insert(_size, e); } //Ĭ����ΪĩԪ�ز���
	void sort(Rank lo, Rank hi); //��[lo, hi)����
	void sort() { sort(0, _size); } //��������
	void unsort(Rank lo, Rank hi); //��[lo, hi)����
	void unsort() { unsort(0, _size); } //��������
	int deduplicate(); //����ȥ��
	int uniquify(); //����ȥ��
 // ����
	void traverse(void (*) (T&)); //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
	template <typename VST> void traverse(VST&); //������ʹ�ú������󣬿�ȫ�����޸ģ�

};

#include"vector_implementation.h"
// ϵͳ�Դ�ͷ�ļ���<>: ��������������ϵͳ�ļ�Ŀ¼�������
// �û��Զ���ͷ�ļ���"":�������������û�Ŀ¼�²��ң�Ȼ��C++��װĿ¼�������ϵͳ�ļ��в���