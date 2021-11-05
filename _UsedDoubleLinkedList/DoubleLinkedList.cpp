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

DoubleLinkedList::DoubleLinkedList(size_t count)
	: DoubleLinkedList()
{
	for (size_t i = 0; i < count; ++i) { push_front(0); }
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other)
	: DoubleLinkedList()
{
	for (auto iter = begin(); iter != end(); iter = iter->Next) { push_back(iter->Data); }
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& rhs)
{
	if (this != &rhs) {
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
	return begin()->Data;
}

const int& DoubleLinkedList::front() const
{
	return begin()->Data;
}

int& DoubleLinkedList::back()
{
	return end()->Prev->Data;
}

const int& DoubleLinkedList::back() const
{
	return end()->Prev->Data;
}

DoubleLinkedList::Node* DoubleLinkedList::begin()
{
	return _head;
}

const DoubleLinkedList::Node* DoubleLinkedList::begin() const
{
	return _head;
}

DoubleLinkedList::Node* DoubleLinkedList::end()
{
	return _end;
}

const DoubleLinkedList::Node* DoubleLinkedList::end() const
{
	return _end;
}

DoubleLinkedList::Node* DoubleLinkedList::insert(Node* pos, int value)
{
	Node* newNode = new Node(value);
	Node* prevNode = pos->Prev;

	pos->Prev = newNode;
	if (prevNode != nullptr) {
		prevNode->Next = newNode;
	}

	newNode->Prev = prevNode;
	newNode->Next = pos;

	if (pos == _head) { _head = newNode; }
	++_size;

	return newNode;
}

DoubleLinkedList::Node* DoubleLinkedList::erase(Node* pos)
{
	if (empty()) { return end(); }
	
	Node* prevNode = pos->Prev;
	Node* nextNode = pos->Next;

	if (prevNode != nullptr) { prevNode->Next = nextNode; }
	if (nextNode != nullptr) { nextNode->Next = prevNode; }
	if (pos == _head) { _head = nextNode; }

	delete pos;
	pos = nullptr;
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
	erase(end()->Prev);
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
	for (auto iter = begin(); iter != end(); iter = iter->Next) {
		if (iter->Data == value) { return true; }
	}
	return false;
}
