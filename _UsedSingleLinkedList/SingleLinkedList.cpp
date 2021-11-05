#include "SingleLinkedList.h"

SingleLinkedList::Node::Node(int data, Node* next)
	: Data{ data }, Next{ next } 
{
}

SingleLinkedList::Node::~Node()
{
	Data = 0;
	Next = nullptr;
}

SingleLinkedList::const_iterator::const_iterator(Node* p)
	: _p{ p }
{
}

SingleLinkedList::const_iterator::~const_iterator()
{
	_p = nullptr;
}

const int& SingleLinkedList::const_iterator::operator*() const
{
	return _p->Data;
}

const int* SingleLinkedList::const_iterator::operator->() const
{
	return &_p->Data;
}

SingleLinkedList::const_iterator& SingleLinkedList::const_iterator::operator++()
{
	_p = _p->Next;
	return *this;
}

SingleLinkedList::const_iterator SingleLinkedList::const_iterator::operator++(int)
{
	auto temp = *this;
	_p = _p->Next;
	return temp;
}

bool SingleLinkedList::const_iterator::operator==(const const_iterator& rhs) const
{
	return _p == rhs._p;
}

bool SingleLinkedList::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

bool SingleLinkedList::const_iterator::operator==(nullptr_t p) const
{
	return _p == nullptr;
}

bool SingleLinkedList::const_iterator::operator!=(nullptr_t p) const
{
	return !(*this == nullptr);
}

int& SingleLinkedList::iterator::operator*() const
{
	return const_cast<int&>(const_iterator::operator*());
}

int* SingleLinkedList::iterator::operator->() const
{
	return const_cast<int*>(const_iterator::operator->());
}

SingleLinkedList::iterator& SingleLinkedList::iterator::operator++()
{
	SingleLinkedList::const_iterator::operator++();
	return *this;
}

SingleLinkedList::iterator SingleLinkedList::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();
	return temp;
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

SingleLinkedList::iterator SingleLinkedList::before_begin()
{
	return iterator(_head);
}

const SingleLinkedList::iterator SingleLinkedList::before_begin() const
{
	return iterator(_head);
}

SingleLinkedList::iterator SingleLinkedList::begin()
{
	return iterator(_head->Next);
}

SingleLinkedList::const_iterator SingleLinkedList::begin() const
{
	return iterator(_head->Next);
}

SingleLinkedList::iterator SingleLinkedList::end()
{
	return iterator(_end);
}

SingleLinkedList::const_iterator SingleLinkedList::end() const
{
	return iterator(_end);
}

SingleLinkedList::iterator SingleLinkedList::insert_after(iterator pos, int value)
{
	Node* where = pos._p;
	Node* newNode = new Node(value);

	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

SingleLinkedList::iterator SingleLinkedList::erase_after(iterator pos)
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
