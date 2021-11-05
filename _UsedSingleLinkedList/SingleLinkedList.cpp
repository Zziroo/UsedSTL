#include "SingleLinkedList.h"

#include <algorithm>

SingleLinkedList::SingleLinkedList()
{
	_head->Next = _end;
}

SingleLinkedList::SingleLinkedList(size_t count)
	: SingleLinkedList()
{
	for (size_t i = 0; i < count; ++i) { push_front(0); }
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList& other)
	: SingleLinkedList()
{
	auto inserted = before_begin();
	for (auto iter = other.begin(); iter != other.end(); iter = iter->Next) { inserted = insert_after(inserted, iter->Data); }
}

SingleLinkedList& SingleLinkedList::operator=(const SingleLinkedList& rhs)
{
	if (this != &rhs) {
		SingleLinkedList temp(rhs);
		std::swap(_head, temp._head);
		std::swap(_end, temp._end);
	}
	return *this;
}

SingleLinkedList::~SingleLinkedList()
{
	clear();

	delete _head;
	_head = nullptr;

	delete _end;
	_end = nullptr;
}

int& SingleLinkedList::front()
{
	return begin()->Data;
}

const int& SingleLinkedList::front() const
{
	return begin()->Data;
}

Node* SingleLinkedList::before_begin()
{
	return _head;
}

const Node* SingleLinkedList::before_begin() const
{
	return _head;
}

Node* SingleLinkedList::begin()
{
	return _head->Next;
}

const Node* SingleLinkedList::begin() const
{
	return _head->Next;
}

Node* SingleLinkedList::end()
{
	return _end;
}

const Node* SingleLinkedList::end() const
{
	return _end;
}

Node* SingleLinkedList::insert_after(Node* pos, int value)
{
	Node* newNode = new Node(value);
	newNode->Next = pos->Next;
	pos->Next = newNode;
	return newNode;
}

Node* SingleLinkedList::erase_after(Node* pos)
{
	Node* removed = pos->Next;
	if (removed == nullptr) { return end(); }

	pos->Next = removed->Next;
	removed->Next = nullptr;

	return removed;
}

void SingleLinkedList::push_front(int value)
{
	insert_after(before_begin(), value);
}

void SingleLinkedList::pop_front()
{
	Node* removed = erase_after(before_begin());
	delete removed;
}

bool SingleLinkedList::empty() const
{
	if (begin() == end()) { return true; }
	else { return false; }
}

void SingleLinkedList::clear()
{
	while (false == empty()) { pop_front(); }
}

bool SingleLinkedList::contains(int value) const
{
	for (auto iter = begin(); iter != end(); iter = iter->Next) {
		if (iter->Data == value) { return true; }
	}
	return false;
}
