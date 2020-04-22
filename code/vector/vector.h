#pragma once

typedef int Rank; //秩
#define DEFAULT_CAPACITY 3 //默认初始容量为3

template<typename T> class  Vector
{

protected:
	Rank _size;
	int _capacity;
	T* _elem; //规模 容量 数据区
	void copyFrom(T const* A, Rank lo, Rank hi); // 复制区间数组
	void expand();//空间不足时进行扩容
	void shrink();//装填因子过小时压缩
	bool bubble(Rank lo, Rank hi);//扫描交换
	void bublleSort(Rank lo, Rank hi);
	Rank max(Rank lo, Rank hi);//选取最大元素
	void selectSort(Rank lo, Rank hi);//选择排序算法
	void merge(Rank lo, Rank mi, Rank hi); //归并排序
	void mergeSort(Rank lo, Rank hi);// 归并排序算法

public:
	// 构造函数
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) // 容量为c 规模为s 所有元素初始为v
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}
	Vector(T const* A, Rank n) { copyFrom(A, 0, n); } //数组整体复制
	Vector(T const* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //数组区间复制
	Vector(Vector<T>const& V) { copyFrom(V._elem, 0, V._size); } //向量整体复制
	Vector(Vector<T>const& V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } // 向量区间复制
	// 析构函数
	~Vector() { delete[]_elem; }
	// 只读访问接口
	Rank size() const { return _size; } //类函数成员声明为const 以表明其不会修改类对象
	bool empty() const { return !_size; }
	Rank find(T const& e, Rank lo, Rank hi) const; //无需向量区间查找
	Rank search(T const& e) const {
		return (0 >= _size) ? -1 : search(e, 0, _size);
	}
	//可写访问接口
	T& operator[] (Rank r); //重载下标操作符，以类似数组的形式引用各元素
	const T& operator[] (Rank r) const; //仅限于做右值的重载版本
	Vector<T>& operator= (Vector<T>const&); //克隆向量
	T remove(Rank r);//删除秩为r的元素
	int remove(Rank lo, Rank hi); //删除区间元素
	Rank insert(Rank r, T const& e); //插入元素
	Rank insert(T const& e) { return insert(_size, e); } //默认作为末元素插入
	void sort(Rank lo, Rank hi); //对[lo, hi)排序
	void sort() { sort(0, _size); } //整体排序
	void unsort(Rank lo, Rank hi); //对[lo, hi)置乱
	void unsort() { unsort(0, _size); } //整体置乱
	int deduplicate(); //无序去重
	int uniquify(); //有序去重
 // 遍历
	void traverse(void (*) (T&)); //遍历（使用函数指针，只读或局部性修改）
	template <typename VST> void traverse(VST&); //遍历（使用函数对象，可全局性修改）

};

#include"vector_implementation.h"
// 系统自带头文件用<>: 这样编译器会在系统文件目录下面查找
// 用户自定义头文件用"":编译器首先在用户目录下查找，然后到C++安装目录，最后在系统文件中查找