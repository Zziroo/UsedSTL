#pragma once
class MyVector
{
private:
	int* _container = nullptr;
	size_t	_size = 0;
	size_t	_capacity = 0;

public:
	MyVector() = default;						// 기본 생성자
	explicit MyVector(size_t count);			// count만큼 공간이 할당된 생성자
	MyVector(const MyVector& other);			// 복사 생성자. 깊은 복사(deep copy)가 이뤄져야 한다.
	MyVector& operator=(const MyVector& rhs);	// 할당 연산자. 깊은 복사(deep copy)가 이뤄져야 한다.
	MyVector(MyVector&& other);					// 이동 생성자
	MyVector& operator=(MyVector&& other);		// 이동 할당 연산자
	~MyVector();								// 소멸자

	// 첫 번째 요소를 가리키는 반복자를 반환한다.
	int* begin();
	const int* begin() const;
	// 마지막 요소의 다음 번째를 가리키는 반복자를 반환한다.
	int* end();
	const int* end() const;
	// 컨데이너의 첫 번째 원소의 참조를 반환한다.
	int& front();
	const int& front() const;
	// 컨테이너의 마지막 원소의 참조를 반환한다.
	int& back();
	const int& back() const;
	// pos에 위치한 원소의 참조를 반환한다.
	int& operator[](size_t pos);
	const int& operator[](size_t pos) const;
	// pos에 위치한 원소의 참조를 반환한다. 만약 pos가 범위에서 벗어나면 std::out_of_range 예외가 던져진다.
	int& at(size_t pos);
	const int& at(size_t pos) const;

	size_t		size() const;					// 원소의 개수를 반환한다.
	size_t		capacity() const;				// 현재 할당된 공간의 크기를 반환한다.

	bool		empty() const;					// 컨테이너가 비었는지 검사한다.
	bool		contains(int value);			// value가 존재하는지 검사한다.

	void		clear();						// 컨테이너를 비운다.

	int*		insert(int* pos, int value);	// pos 이전 위치에 value를 삽입한다. value가 삽입된 곳을 가리키는 포인터를 반환한다.
	int*		erase(int* pos);				// pos에 위치한 원소를 지운다. 삭제된 요소의 다음 포인터를 반환한다.
	void		push_back(int value);			// 컨테이너의 맨 끝에 원소를 추가한다.
	void		pop_back();						// 컨테이너의 마지막 원소를 삭제한다.

	void		reserve(size_t newCapacity);	// 컨테이너의 용량을 newCapacity보다 같거나 크게 늘린다.
};

