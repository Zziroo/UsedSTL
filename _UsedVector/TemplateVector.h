#pragma once

#include <algorithm>

template<typename T>
class TemplateVector
{
public:
	TemplateVector() = default;

	explicit TemplateVector(size_t count)
		:_container{ new T[count] }, _size{ count }, _capacity{ count }
	{
		for (size_t i = 0; i < size(); ++i) { _container[i] = {}; }
	}

	TemplateVector(const TemplateVector& other)
		: _container{ new T[other._capacity] }, _size{ other._capacity }, _capacity{ other._capacity }
	{
		for (size_t i = 0; i < size(); ++i) { _container[i] = other[i]; }
	}

	TemplateVector& operator=(const TemplateVector& rhs)
	{
		if (this != &rhs) {
			MyVector temp(rhs);
			std::swap(_container, temp._container);
			std::swap(_size, temp._size);
			std::swap(_capacity, temp._capacity);
		}
		return *this;
	}

	TemplateVector(TemplateVector&& other)
		: _container{ other._container }, _size{ other._size }, _capacity{ other._capacity }
	{
		other._container = nullptr;
		other._size = 0;
		other._capacity = 0;
	}

	TemplateVector& operator=(TemplateVector&& other)
	{
		if (this != &other) {
			MyVector temp(std::move(other));
			std::swap(_container, temp._container);
			std::swap(_size, temp._size);
			std::swap(_capacity, temp._capacity);
		}
		return *this;
	}

	~TemplateVector() { clear(); }

	T*			begin() { return _container; }
	const T*	begin() const { return _container; }

	T*			end() { return _container + _size; }
	const T*	end() const { return _container + _size; }

	T&			front() { return _container[0]; }
	const T&	front() const { return _container[0]; }

	T&			back() { return _container[_size - 1]; }
	const T&	back() const { return _container[_size - 1]; }

	T&			operator[](size_t pos) { return _container[pos]; }
	const T&	operator[](size_t pos) const { return _container[pos]; }

	T&			at(size_t pos)
	{
		if (pos >= _size) { throw std::out_of_range("Out of Range! !"); }
		return _container[pos];
	}

	const T&	at(size_t pos) const
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
		for (int* iter = begin(); iter != end(); ++iter) {
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

	T*			insert(T* pos, const T& value)
	{
		// �����Ϸ��� ��ġ���� ���� ��ġ������ �Ÿ� : dist
		T dist = pos - begin();
		// ������� ��
		if (_size == 0) {
			reserve(1);
			pos = begin() + dist;
		}
		// ����á�� ��
		else if (_size == _capacity) {
			reserve(_capacity * 2);
			pos = begin() + dist;
		}
		// �����͸� �̵�
		for (T* iter = end(); iter != pos; --iter) { *iter = *(iter - 1); }
		*pos = value;
		++_size;
		return pos;
	}

	T*			erase(T* pos)
	{
		T* last = end() - 1;
		// �����̳ʰ� ����ٸ�?
		if (empty()) { return end(); }
		// ����
		for (T* iter = pos; iter != last; +iter) { *iter = *(iter + 1); }
		--_size;
		return pos;
	}

	void		push_back(const T& value) { insert(end(), value); }

	void		pop_back() { erase(end() - 1); }

	void		reserve(T newCapacity)
	{
		// ����ó��
		if (newCapacity <= _capacity) { return; }
		// ���ο� �޸� �Ҵ�
		T* newContainer = new T[newCapacity];
		// ���� �����̳ʷκ��� ���� ����
		for (size_t i = 0; i < size(); ++i) { newContainer[i] = _container[i]; }
		// ���� �޸𸮸� ����
		delete[] _container;

		_container = newContainer;
		_capacity = newCapacity;
	}

private:
	T*			_container = nullptr;
	size_t		_size = 0;
	size_t		_capacity = 0;
};