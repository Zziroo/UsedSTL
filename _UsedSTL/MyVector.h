#pragma once

class MyVector
{
private:
	int* _container = nullptr;
	size_t	_size = 0;
	size_t	_capacity = 0;

public:
	MyVector() = default;						// �⺻ ������
	explicit MyVector(size_t count);			// count��ŭ ������ �Ҵ�� ������
	MyVector(const MyVector& other);			// ���� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
	MyVector& operator=(const MyVector& rhs);	// �Ҵ� ������. ���� ����(deep copy)�� �̷����� �Ѵ�.
	MyVector(MyVector&& other);					// �̵� ������
	MyVector& operator=(MyVector&& other);		// �̵� �Ҵ� ������
	~MyVector();								// �Ҹ���

	// ù ��° ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	int* begin();
	const int* begin() const;
	// ������ ����� ���� ��°�� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	int* end();
	const int* end() const;
	// �����̳��� ù ��° ������ ������ ��ȯ�Ѵ�.
	int& front();
	const int& front() const;
	// �����̳��� ������ ������ ������ ��ȯ�Ѵ�.
	int& back();
	const int& back() const;
	// pos�� ��ġ�� ������ ������ ��ȯ�Ѵ�.
	int& operator[](size_t pos);
	const int& operator[](size_t pos) const;
	// pos�� ��ġ�� ������ ��ȯ�Ѵ�. ���� pos�� �������� ����� std::out_of_range ���ܰ� ��������.
	int& at(size_t pos);
	const int& at(size_t pos) const;

	size_t		size() const;					// ������ ������ ��ȯ�Ѵ�.
	size_t		capacity() const;				// ���� �Ҵ�� ������ ũ�⸦ ��ȯ�Ѵ�.

	bool		empty() const;					// �����̳ʰ� ������� �˻��Ѵ�.
	bool		contains(int value);			// value�� �����ϴ��� �˻��Ѵ�.

	void		clear();						// �����̳ʸ� ����.

	int* insert(int* pos, int value);	// pos ���� ��ġ�� value�� �����Ѵ�. value�� ���Ե� ���� ����Ű�� �����͸� ��ȯ�Ѵ�.
	int* erase(int* pos);				// pos�� ��ġ�� ���Ҹ� �����. ������ ����� ���� �����͸� ��ȯ�Ѵ�.
	void		push_back(int value);			// �����̳��� �� ���� ���Ҹ� �߰��Ѵ�.
	void		pop_back();						// �����̳��� ������ ���Ҹ� �����Ѵ�.

	void		reserve(size_t newCapacity);	// �����̳��� �뷮�� newCapacity���� ���ų� ũ�� �ø���.
};

