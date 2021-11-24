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
	// ������ ��忡 ���� �߰��Ѵ�.
	_container.push_back(value);

	// �θ�� ���ϸ鼭 ���� �Һ����� ������ ������ ��ġ�� �ٲ��ش�.
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

	// ���� ������ ��带 ��Ʈ ��忡 ������ش�.
	_container[0] = _container[size() - 1];
	_container.pop_back();

	// ���� �Һ����� ������ ������ �ڽ� ���� �ٲ��ش�.
	size_t curr = 1;
	size_t child = 2;

	while (child <= _container.size())
	{
		// ������ �ڽ��� ���� �ڽĺ��� �� ũ�ٸ� ������ �ڽİ� ���Ѵ�.
		if (child + 1 <= _container.size() && _container[child - 1] < _container[child + 1 - 1]) { ++child; }
		// �̹� ���� �Һ����� �����Ѵٸ� �ߴ��Ѵ�.
		if (_container[curr - 1] >= _container[child - 1]) { break; }

		swap(_container[curr - 1], _container[child - 1]);

		curr = child;
		child = curr * 2;
	}
}
