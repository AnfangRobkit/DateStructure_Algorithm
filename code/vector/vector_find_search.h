#pragma once
template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi]));
	return hi; // 若hi<lo, 则意味着失败，返回lo
}