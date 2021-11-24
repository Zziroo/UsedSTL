#pragma once

#include <vector>

using namespace std;

class MyHeap
{
public:
	MyHeap() = default;
	~MyHeap() = default;
	
	const int&		top() const;		// �ִ� ���Ҹ� ��ȯ�Ѵ�.
	bool			empty() const;		// ���� ����ִ��� Ȯ���Ѵ�.
	size_t			size() const;		// ���� ũ�⸦ ��ȯ�Ѵ�.
	void			push(int value);	// ���� ���Ҹ� �����Ѵ�.
	void			pop();				// ������ ���Ҹ� �����Ѵ�.

private:
	vector<int>		_container;
};