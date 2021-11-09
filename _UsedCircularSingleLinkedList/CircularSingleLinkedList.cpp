#include "CircularSingleLinkedList.h"

#include <utility>

CircularSingleLinkedList::CircularSingleLinkedList(const CircularSingleLinkedList& other)
    : CircularSingleLinkedList()
{
    if (other.empty()) { return; }

    auto iter = other.head();
    do
    {
        push_back(iter->Data);

        iter = iter->Next;
    } while (iter != other.head());
}

CircularSingleLinkedList& CircularSingleLinkedList::operator=(const CircularSingleLinkedList& rhs)
{
    if (this != &rhs)
    {
        CircularSingleLinkedList temp(rhs);
        std::swap(_beforeHead, temp._beforeHead);
        std::swap(_beforeTail, temp._beforeTail);
    }
    return *this;
}

CircularSingleLinkedList::~CircularSingleLinkedList()
{
    clear();

    delete _beforeHead;
    _beforeHead = nullptr;
    _beforeTail = nullptr;
}

int& CircularSingleLinkedList::front()
{
    return head()->Data;
}

const int& CircularSingleLinkedList::front() const
{
    return head()->Data;
}

int& CircularSingleLinkedList::back()
{
    return tail()->Data;
}

const int& CircularSingleLinkedList::back() const
{
    return tail()->Data;
}

CircularSingleLinkedList::Node* CircularSingleLinkedList::before_head()
{
    return _beforeHead;
}

const CircularSingleLinkedList::Node* CircularSingleLinkedList::before_head() const
{
    return _beforeHead;
}

CircularSingleLinkedList::Node* CircularSingleLinkedList::before_tail()
{
    return _beforeTail;
}

const CircularSingleLinkedList::Node* CircularSingleLinkedList::before_tail() const
{
    return _beforeTail;
}

CircularSingleLinkedList::Node* CircularSingleLinkedList::head()
{
    return before_head()->Next;
}

const CircularSingleLinkedList::Node* CircularSingleLinkedList::head() const
{
    return before_head()->Next;
}

CircularSingleLinkedList::Node* CircularSingleLinkedList::tail()
{
    return before_tail()->Next;
}

const CircularSingleLinkedList::Node* CircularSingleLinkedList::tail() const
{
    return before_tail()->Next;
}

CircularSingleLinkedList::Node* CircularSingleLinkedList::insert_after(Node* pos, int value)
{
    Node* newNode = new Node(value);
    newNode->Next = pos->Next;
    pos->Next = newNode;

    // ù ��° ���Ұ� ���Ե� ��
    if (head()->Next == nullptr) { head()->Next = head(); }
    // �� ��° ���Ұ� ���Ե� ��
    else if (before_head() == before_tail())
    {
        _beforeTail = head();
        tail()->Next = head();
    }
    // before_tail / tail�� ������ ��
    else if (pos == before_tail() || pos == tail()) { _beforeTail = _beforeTail->Next; }
    // before_head�� ������ ��
    else if (pos == before_head()) { tail()->Next = head(); }

    return newNode;
}

CircularSingleLinkedList::Node* CircularSingleLinkedList::erase_after(Node* pos)
{
    if (empty()) { return tail(); }

    Node* removed = pos->Next;

    // ���Ұ� �ϳ��� ��
    if (head()->Next == head()) { before_head()->Next = nullptr; }
    // ���Ұ� �ΰ��� ��
    else if (before_tail() == head())
    {
        before_head()->Next = removed->Next;
        _beforeTail = before_head();
        tail()->Next = head();
    }
    // tail�� �����Ϸ��� �� ��
    else if (pos == before_tail())
    {
        before_tail()->Next = removed->Next;
        while (tail()->Next != head()) { _beforeTail = _beforeTail->Next; }
    }
    // before_tail�� ���ŵ� ��
    else if (removed == before_tail())
    {
        pos->Next = removed->Next;
        _beforeTail = pos;
    }
    // ù �κ��� ���ŵ� ��
    else if (removed == head())
    {
        before_head()->Next = removed->Next;
        tail()->Next = head();
    }
    else { pos->Next = removed->Next; }

    removed->Next = nullptr;

    return removed;
}

void CircularSingleLinkedList::push_front(int value)
{
    insert_after(before_head(), value);
}

void CircularSingleLinkedList::push_back(int value)
{
    if (empty()) { insert_after(before_head(), value); }
    else { insert_after(tail(), value); }
}

void CircularSingleLinkedList::pop_front()
{
    Node* erased = erase_after(before_head());
    delete erased;
}

void CircularSingleLinkedList::pop_back()
{
    Node* erased = erase_after(before_tail());
    delete erased;
}

bool CircularSingleLinkedList::empty() const
{
    if (head() == nullptr) { return true; }
    else { return false; }
}

void CircularSingleLinkedList::clear()
{
    while (empty() == false) { pop_front(); }
}

bool CircularSingleLinkedList::contains(int value) const
{
    if (empty()) { return false; }

    auto iter = head();
    do
    {
        if (iter->Data == value) { return true; }
        iter = iter->Next;
    } while (iter != head());

    return false;
}
