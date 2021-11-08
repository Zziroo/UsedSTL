#include "DoubleLinkedList.h"

DoubleLinkedList::Node::Node(int data, Node* prev, Node* next)
	: Data{ data }, Prev{ prev }, Next{ next }
{
}

DoubleLinkedList::Node::~Node()
{
	Next = nullptr;
	Prev = nullptr;
}

DoubleLinkedList::const_iterator::const_iterator(Node* p)
	: _p{ p }
{
}

DoubleLinkedList::const_iterator::~const_iterator()
{
	_p = nullptr;
}

const int& DoubleLinkedList::const_iterator::operator*() const
{
	return _p->Data;
}

const int* DoubleLinkedList::const_iterator::operator->() const
{
	return &_p->Data;
}

DoubleLinkedList::const_iterator& DoubleLinkedList::const_iterator::operator++()
{
	_p = _p->Next;
	return *this;
}

DoubleLinkedList::const_iterator DoubleLinkedList::const_iterator::operator++(int)
{
	auto temp = *this;
	_p = _p->Next;
	return temp;
}

DoubleLinkedList::const_iterator& DoubleLinkedList::const_iterator::operator--()
{
	_p = _p->Prev;
	return *this;
}

DoubleLinkedList::const_iterator DoubleLinkedList::const_iterator::operator--(int)
{
	auto temp = *this;
	_p = _p->Prev;
	return temp;
}

bool DoubleLinkedList::const_iterator::operator==(const const_iterator& rhs) const
{
	return _p == rhs._p;
}

bool DoubleLinkedList::const_iterator::operator!=(const const_iterator& rhs) const
{
	return!(*this == rhs._p);
}

bool DoubleLinkedList::const_iterator::operator==(nullptr_t p) const
{
	return _p == nullptr;
}

bool DoubleLinkedList::const_iterator::operator!=(nullptr_t p) const
{
	return !(*this == nullptr);
}

int& DoubleLinkedList::iterator::operator*() const
{
	return const_cast<int&>(const_iterator::operator*());
}

int* DoubleLinkedList::iterator::operator->() const
{
	return const_cast<int*>(const_iterator::operator->());
}

DoubleLinkedList::iterator& DoubleLinkedList::iterator::operator++()
{
	const_iterator::operator++();
	return *this;
}

DoubleLinkedList::iterator DoubleLinkedList::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();
	return temp;
}

DoubleLinkedList::iterator& DoubleLinkedList::iterator::operator--()
{
	const_iterator::operator--();
	return *this;
}

DoubleLinkedList::iterator DoubleLinkedList::iterator::operator--(int)
{
	iterator temp = *this;
	const_iterator::operator--();
	return temp;
}

DoubleLinkedList::DoubleLinkedList(size_t count)
	: DoubleLinkedList()
{
	for (size_t i = 0; i < count; ++i) { push_front(0); }
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other)
	: DoubleLinkedList()
{
	for (auto iter = begin(); iter != end(); ++iter) { push_back(*iter); }
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& rhs)
{
	if (this != &rhs) 
	{
		DoubleLinkedList temp(rhs);
		std::swap(_end, temp._end);
		std::swap(_head, temp._head);
		std::swap(_size, temp._size);
	}
	return *this;
}

DoubleLinkedList::~DoubleLinkedList()
{
	clear();
	
	delete _end;
	_end = nullptr;

	_head = 0;
	//delete _head;
	//_head = nullptr;

	_size = 0;
}

int& DoubleLinkedList::front()
{
	return *begin();
}

const int& DoubleLinkedList::front() const
{
	return *begin();
}

int& DoubleLinkedList::back()
{
	return *(--end());
}

const int& DoubleLinkedList::back() const
{
	return *(--end());
}

DoubleLinkedList::iterator DoubleLinkedList::begin()
{
	return iterator(_head);
}

DoubleLinkedList::const_iterator DoubleLinkedList::begin() const
{
	return const_iterator(_head);
}

DoubleLinkedList::iterator DoubleLinkedList::end()
{
	return iterator(_end);
}

DoubleLinkedList::const_iterator DoubleLinkedList::end() const
{
	return const_iterator(_end);
}

DoubleLinkedList::iterator DoubleLinkedList::insert(iterator pos, int value)
{
	Node* where = pos._p;
	Node* newNode = new Node(value);
	Node* prevNode = where->Prev;

	where->Prev = newNode;
	if (prevNode != nullptr) 
	{
		prevNode->Next = newNode;
	}

	newNode->Prev = prevNode;
	newNode->Next = where;

	if (pos == _head) { _head = newNode; }
	++_size;

	return newNode;
}

DoubleLinkedList::iterator DoubleLinkedList::erase(iterator pos)
{
	if (empty()) { return end(); }
	
	Node* where = pos._p;
	Node* prevNode = where->Prev;
	Node* nextNode = where->Next;

	if (prevNode != nullptr) { prevNode->Next = nextNode; }
	if (nextNode != nullptr) { nextNode->Prev = prevNode; }
	if (pos == _head) { _head = nextNode; }

	delete where;
	where = nullptr;
	--_size;
	
	return nextNode;
}

void DoubleLinkedList::push_front(int value)
{
	insert(begin(), value);
}

void DoubleLinkedList::push_back(int value)
{
	insert(end(), value);
}

void DoubleLinkedList::pop_front()
{
	erase(begin());
}

void DoubleLinkedList::pop_back()
{
	erase(--end());
}

bool DoubleLinkedList::empty() const
{
	if (_size == 0) { return true; }
	else { return false; }
}

size_t DoubleLinkedList::size() const
{
	return _size;
}

void DoubleLinkedList::clear()
{
	while (false == empty()) { pop_front(); }
}

bool DoubleLinkedList::contains(int value) const
{
	for (auto iter = begin(); iter != end(); ++iter) 
	{
		if (*iter == value) { return true; }
	}
	return false;
}
