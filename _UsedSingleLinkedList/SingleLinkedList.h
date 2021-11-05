#pragma once

#include <algorithm>

class SingleLinkedList
{
public:
    struct Node
    {
        Node(int data = 0, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int     Data = 0;
        Node*   Next = nullptr;
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
    };

public:
    SingleLinkedList();                                         // �⺻ ������
    explicit SingleLinkedList(size_t count);                    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    SingleLinkedList(const SingleLinkedList& other);            // ���� ������.
    SingleLinkedList& operator=(const SingleLinkedList& rhs);   // �Ҵ� ������
    ~SingleLinkedList();                                        // �Ҹ���
    
    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int&            front();
    const int&      front() const;
    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator        before_begin();
    const iterator  before_begin() const;

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator        begin();
    const_iterator  begin() const;
    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator        end();
    const_iterator  end() const;

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    iterator        insert_after(iterator pos, int value);
    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    iterator        erase_after(iterator pos);
    
    void            push_front(int value);      // ���� ��ҿ� value�� �����Ѵ�.
    void            pop_front();                // ���� ��Ҹ� �����Ѵ�.
    bool            empty() const;              // �����̳ʰ� ������� �Ǵ��Ѵ�.
    void            clear();                    // �����̳ʸ� ���������.
    bool            contains(int value) const;  // value�� �ִ��� ������ �Ǵ��Ѵ�.

private:
    Node* _head = new Node();
    Node* _end = new Node();
};


