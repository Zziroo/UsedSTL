#pragma once

#include <stdexcept>

class MyVector
{
public:
	MyVector() = default;

	explicit MyVector(size_t count)
		: _container{ new int[count] }, _size{ count }, _capacity{ count }
	{
		for (size_t i = 0; i < size(); ++i) { _container[i] = {}; }
	}

	MyVector(const MyVector& other)
		: _container{ new int[other._capacity] }, _size{ other._capacity }, _capacity{ other._capacity }
	{
		for (size_t i = 0; i < size(); ++i) { _container[i] = other[i]; }
	}

	MyVector& operator=(const MyVector& rhs)
	{
		if (this != &rhs) {
			MyVector temp(rhs);
			std::swap(_container, temp._container);
			std::swap(_size, temp._size);
			std::swap(_capacity, temp._capacity);
		}
		return *this;
	}

	MyVector(MyVector&& other)
		: _container{ other._container }, _size{ other._size }, _capacity{ other._capacity }
	{
		other._container = nullptr;
		other._size = 0;
		other._capacity = 0;
	}

	MyVector& operator=(MyVector&& other)
	{
		if (this != &other)
		{
			MyVector temp(std::move(other));
			std::swap(_container, temp._container);
			std::swap(_size, temp._size);
			std::swap(_capacity, temp._capacity);
		}
		return *this;
	}

	~MyVector() { clear(); }

	// 첫 번째 요소를 가리키는 반복자를 반환한다.
	int* begin() { return _container; }
	const int* begin() const { return _container; }
	// 마지막 요소의 다음 번째를 가리키는 반복자를 반환한다.
	int* end() { return _container + _size; }
	const int* end() const { return _container + _size; }
	// 컨데이너의 첫 번째 원소의 참조를 반환한다.
	int& front() { return _container[0]; }
	const int& front() const { return _container[0]; }
	// 컨테이너의 마지막 원소의 참조를 반환한다.
	int& back() { return _container[_size - 1]; }
	const int& back() const { return _container[_size - 1]; }
	// pos에 위치한 원소의 참조를 반환한다.
	int& operator[](size_t pos) { return _container[pos]; }
	const int& operator[](size_t pos) const { return _container[pos]; }
	// pos에 위치한 원소의 참조를 반환한다. 만약 pos가 범위에서 벗어나면 std::out_of_range 예외가 던져진다.
	int& at(size_t pos)
	{
		if (pos >= _size) { throw std::out_of_range("Out of Range! !"); }
		return _container[pos];
	}
	const int& at(size_t pos) const
	{
		if (pos >= _size) { throw std::out_of_range("Out of Range! !"); }
		return _container[pos];
	}

	size_t		size() const { return _size; }
	size_t		capacity() const { return _capacity; }

	bool		empty() const
	{
		if (_size == 0) { return true; }
		else { return false; }
	}

	bool		contains(int value)
	{
		for (int* iter = begin(); iter != end(); ++iter)
		{
			if (*iter == value) { return true; }
		}
		return false;
	}

	void		clear()
	{
		delete[] _container;
		_container = nullptr;

		_size = 0;
		_capacity = 0;
	}

	int* insert(int* pos, int value)
	{
		ptrdiff_t dist = pos - begin();

		if (_size == 0)
		{
			reserve(1);
			pos = begin() + dist;
		}
		else if (_size == _capacity)
		{
			reserve(_capacity * 2);
			pos = begin() + dist;
		}

		for (int* iter = end(); iter != pos; --iter) { *iter = *(iter - 1); }
		*pos = value;
		++_size;

		return pos;
	}

	int* erase(int* pos)
	{
		int* last = end() - 1;
		if (empty()) { return end(); }

		for (int* iter = pos; iter != end(); ++iter) { *iter = *(iter + 1); }
		--_size;

		return pos;
	}

	void		push_back(int value) { insert(end(), value); }

	void		pop_back() { erase(end() - 1); }

	void		reserve(size_t newCapacity)
	{
		if (newCapacity <= _capacity) { return; }

		int* newContainer = new int[newCapacity];
		for (size_t i = 0; i < size(); ++i) { newContainer[i] = _container[i]; }

		delete[] _container;

		_container = newContainer;
		_capacity = newCapacity;
	}

private:
	int*		_container = nullptr;
	size_t		_size = 0;
	size_t		_capacity = 0;
};