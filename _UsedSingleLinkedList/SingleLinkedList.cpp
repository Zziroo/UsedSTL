#include "SingleLinkedList.h"

Node::Node(int data, Node* next)
	: Data{ data }, Next{ next } 
{
}

Node::~Node()
{
	Data = 0;
	Next = nullptr;
}

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
	for (auto iter = other.begin(); iter != other.end(); ++iter) { inserted = insert_after(inserted, *iter); }
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
	return *begin();
}

const int& SingleLinkedList::front() const
{
	return *begin();
}

iterator SingleLinkedList::before_begin()
{
	return iterator(_head);
}

const iterator SingleLinkedList::before_begin() const
{
	return iterator(_head);
}

iterator SingleLinkedList::begin()
{
	return iterator(_head->Next);
}

const iterator SingleLinkedList::begin() const
{
	return iterator(_head->Next);
}

iterator SingleLinkedList::end()
{
	return iterator(_end);
}

const iterator SingleLinkedList::end() const
{
	return iterator(_end);
}

iterator SingleLinkedList::insert_after(iterator pos, int value)
{
	Node* where = pos._p;
	Node* newNode = new Node(value);
	newNode->Next = where->Next;
	where->Next = newNode;
	return newNode;
}

iterator SingleLinkedList::erase_after(iterator pos)
{
	Node* where = pos._p;
	Node* removed = where->Next;
	if (removed == nullptr) { return end(); }

	where->Next = removed->Next;
	removed->Next = nullptr;

	return removed;
}

void SingleLinkedList::push_front(int value)
{
	insert_after(before_begin(), value);
}

void SingleLinkedList::pop_front()
{
	iterator removed = erase_after(before_begin());
	delete removed._p;
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
	for (auto iter = begin(); iter != end(); ++iter) {
		if (*iter == value) { return true; }
	}
	return false;
}

const_iterator::const_iterator(Node* p)
	: _p{ p } 
{
}

const_iterator::~const_iterator()
{
	_p = nullptr;
}

const int& const_iterator::operator*() const
{
	return _p->Data;
}

const int* const_iterator::operator->() const
{
	return &_p->Data;
}

const_iterator& const_iterator::operator++()
{
	_p = _p->Next;
	return *this;
}

const_iterator const_iterator::operator++(int)
{
	auto temp = *this;
	_p = _p->Next;
	return temp;
}

bool const_iterator::operator==(const const_iterator& rhs) const
{
	return _p == rhs._p;
}

bool const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

bool const_iterator::operator==(nullptr_t p) const
{
	return _p == nullptr;
}

bool const_iterator::operator!=(nullptr_t p) const
{
	return !(*this == nullptr);
}

int& iterator::operator*() const
{
	return const_cast<int&>(const_iterator::operator*());
}

int* iterator::operator->() const
{
	return const_cast<int*>(const_iterator::operator->());
}

iterator& iterator::operator++()
{
	const_iterator::operator++();
	return *this;
}

iterator iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();
	return temp;
}
