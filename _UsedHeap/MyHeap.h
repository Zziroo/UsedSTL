#pragma once

#include <vector>

using namespace std;

class MyHeap
{
public:
	MyHeap() = default;
	~MyHeap() = default;
	
	const int&		top() const;		// 최대 원소를 반환한다.
	bool			empty() const;		// 힙이 비어있는지 확인한다.
	size_t			size() const;		// 힙의 크기를 반환한다.
	void			push(int value);	// 힙에 원소를 삽입한다.
	void			pop();				// 힙에서 원소를 삭제한다.

private:
	vector<int>		_container;
};