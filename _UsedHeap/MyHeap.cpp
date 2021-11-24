#include "MyHeap.h"

const int& MyHeap::top() const
{
	return _container.front();
}

bool MyHeap::empty() const
{
	return _container.empty();
}

size_t MyHeap::size() const
{
	return _container.size();
}

void MyHeap::push(int value)
{
	// 마지막 노드에 값을 추가한다.
	_container.push_back(value);

	// 부모와 비교하면서 힙의 불변성을 만족할 때까지 위치를 바꿔준다.
	size_t curr = _container.size();
	size_t parent = curr / 2;

	while (curr > 1 && _container[parent - 1] < _container[curr - 1])
	{
		swap(_container[parent - 1], _container[curr - 1]);

		curr = parent;
		parent = curr / 2;
	}
}

void MyHeap::pop()
{
	if (empty()) { return; }

	// 가장 마지막 노드를 루트 노드에 만들어준다.
	_container[0] = _container[size() - 1];
	_container.pop_back();

	// 힙의 불변성을 만족할 때까지 자식 노드와 바꿔준다.
	size_t curr = 1;
	size_t child = 2;

	while (child <= _container.size())
	{
		// 오른쪽 자식이 왼쪽 자식보다 더 크다면 오른쪽 자식과 비교한다.
		if (child + 1 <= _container.size() && _container[child - 1] < _container[child + 1 - 1]) { ++child; }
		// 이미 힙의 불변성을 만족한다면 중단한다.
		if (_container[curr - 1] >= _container[child - 1]) { break; }

		swap(_container[curr - 1], _container[child - 1]);

		curr = child;
		child = curr * 2;
	}
}
