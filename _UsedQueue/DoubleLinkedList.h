#pragma once

#include <stdexcept>

class DoubleLinkedList
{
public:
    struct Node
    {
        Node(int data = 0, Node* prev = nullptr, Node* next = nullptr)
            : Data{ data }, Prev{ prev }, Next{ next } {}
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node()
        {
            Next = nullptr;
            Prev = nullptr;
        }

        int     Data;
        Node* Next;
        Node* Prev;
    };

    class const_iterator
    {
    public:
        const_iterator(Node* p = nullptr)
            : _p{ p } {}
        ~const_iterator() { _p = nullptr; }

        const int& operator*() const { return _p->Data; }
        const int* operator->() const { return &_p->Data; }

        const_iterator& operator++()
        {
            _p = _p->Next;
            return *this;
        }

        const_iterator operator++(int)
        {
            auto temp = *this;
            _p = _p->Next;
            return temp;
        }

        const_iterator& operator--()
        {
            _p = _p->Prev;
            return *this;
        }

        const_iterator operator--(int)
        {
            auto temp = *this;
            _p = _p->Prev;
            return temp;
        }

        bool operator==(const const_iterator& rhs) const { return _p == rhs._p; }
        bool operator!=(const const_iterator& rhs) const { return!(*this == rhs._p); }
        bool operator==(nullptr_t p) const { return _p == nullptr; }
        bool operator!=(nullptr_t p) const { return !(*this == nullptr); }

    public:
        Node* _p = nullptr;
    };

    class iterator : public const_iterator
    {
    public:
        using const_iterator::const_iterator;

        int& operator*() const { return const_cast<int&>(const_iterator::operator*()); }
        int* operator->() const { return const_cast<int*>(const_iterator::operator->()); }
        iterator& operator++()
        {
            const_iterator::operator++();
            return *this;
        }

        iterator operator++(int)
        {
            iterator temp = *this;
            const_iterator::operator++();
            return temp;
        }

        iterator& operator--()
        {
            const_iterator::operator--();
            return *this;
        }

        iterator operator--(int)
        {
            iterator temp = *this;
            const_iterator::operator--();
            return temp;
        }
    };

public:
    DoubleLinkedList() = default;

    explicit DoubleLinkedList(size_t count)
        : DoubleLinkedList()
    {
        for (size_t i = 0; i < count; ++i) { push_front(0); }
    }

    DoubleLinkedList(const DoubleLinkedList& other)
        : DoubleLinkedList()
    {
        for (auto iter = begin(); iter != end(); ++iter) { push_back(*iter); }
    }

    DoubleLinkedList& operator=(const DoubleLinkedList& rhs)
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

    ~DoubleLinkedList()
    {
        clear();

        delete _end;
        _end = nullptr;

        _head = 0;
        _size = 0;
    }

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int&            front() { return *begin(); }
    const int&      front() const { return *begin(); }

    // ������ ��Ҹ� ��ȯ�Ѵ�.
    int&            back() { return *(--end()); }
    const int&      back() const { return *(--end()); }

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // ����Ʈ�� ����ִٸ� end()�� ����.
    iterator        begin() { return iterator(_head); }
    const_iterator  begin() const { return const_iterator(_head); }

    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator        end() { return iterator(_end); }
    const_iterator  end() const { return const_iterator(_end); }

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator        insert(iterator pos, int value)
    {
        Node* where = pos._p;
        Node* newNode = new Node(value);
        Node* prevNode = where->Prev;

        where->Prev = newNode;
        if (prevNode != nullptr) { prevNode->Next = newNode; }

        newNode->Prev = prevNode;
        newNode->Next = where;

        if (pos == _head) { _head = newNode; }
        ++_size;

        return newNode;
    }

    // pos ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    iterator        erase(iterator pos)
    {
        if (empty()) { return end(); }
        Node* where = pos._p;
        Node* prevNode = where->Prev;
        Node* nextNode = where->Next;

        if (prevNode != nullptr) { prevNode->Next = nextNode; }
        if (nextNode != nullptr) { nextNode->Prev = prevNode; }

        delete where;
        where = nullptr;
        --_size;

        return nextNode;
    }

    void            push_front(int value) { insert(begin(), value); }
    void            push_back(int value) { insert(end(), value); }
    void            pop_front() { erase(begin()); }
    void            pop_back() { erase(--end()); }
    bool            empty() const
    {
        if (_size == 0) { return true; }
        else { return false; }
    }

    size_t          size() const { return _size; }
    void            clear()
    {
        while (false == empty()) { pop_front(); }
    }

    bool            contains(int value) const
    {
        for (auto iter = begin(); iter != end(); ++iter)
        {
            if (*iter == value) { return true; }
        }
        return false;
    }

private:
    Node*           _end = new Node();
    Node*           _head = _end;
    size_t          _size = 0;
};