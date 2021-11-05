#pragma once

#include <stdexcept>

class DoubleLinkedList
{
public:
    struct Node
    {
        Node(int data = 0, Node* prev = nullptr, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int     Data;
        Node*   Next;
        Node*   Prev;
    };

    class const_iterator
    {
    public:
        const_iterator(Node* p = nullptr);
        ~const_iterator();

        const int& operator*() const;
        const int* operator->() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        bool operator==(const const_iterator& rhs) const;
        bool operator!=(const const_iterator& rhs) const;
        bool operator==(nullptr_t p) const;
        bool operator!=(nullptr_t p) const;

    public:
        Node* _p = nullptr;
    };

    class iterator : public const_iterator
    {
    public:
        using const_iterator::const_iterator;

        int& operator*() const;
        int* operator->() const;
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
    };

public:
    DoubleLinkedList() = default;                               // �⺻ ������
    explicit DoubleLinkedList(size_t count);                    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    DoubleLinkedList(const DoubleLinkedList& other);            // ���� ������.
    DoubleLinkedList& operator=(const DoubleLinkedList& rhs);   // �Ҵ� ������
    ~DoubleLinkedList();                                        // �Ҹ���

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int&            front();
    const int&      front() const;

    // ������ ��Ҹ� ��ȯ�Ѵ�.
    int&            back();
    const int&      back() const;

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // ����Ʈ�� ����ִٸ� end()�� ����.
    iterator        begin();
    const_iterator  begin() const;

    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator        end();
    const_iterator  end() const;

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator        insert(iterator pos, int value);

    // pos ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    iterator        erase(iterator pos);

    void            push_front(int value);      // ���ۿ� value�� �����Ѵ�.
    void            push_back(int value);       // ���� value�� �����Ѵ�.
    void            pop_front();                // ���� ��Ҹ� �����Ѵ�.
    void            pop_back();                 // �� ��Ҹ� �����Ѵ�.
    bool            empty() const;              // �����̳ʰ� ������� �Ǵ��Ѵ�.
    size_t          size() const;               // ����Ʈ �ȿ� �ִ� ����� ������ ��ȯ�Ѵ�.
    void            clear();                    // �����̳ʸ� ���������.
    bool            contains(int value) const;  // �ش� value�� �ִ��� üũ�Ѵ�.

private:
    Node*           _end = new Node();
    Node*           _head = _end;
    size_t          _size = 0;
};


