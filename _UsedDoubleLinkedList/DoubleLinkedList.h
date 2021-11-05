#pragma once

#include <stdexcept>

class DoubleLinkedList
{
public:
    struct Node
    {
    public:
        Node(int data = 0, Node* prev = nullptr, Node* next = nullptr);
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node();

        int     Data;
        Node*   Next;
        Node*   Prev;
    };

public:
    DoubleLinkedList() = default;                               // �⺻ ������
    explicit DoubleLinkedList(size_t count);                    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    DoubleLinkedList(const DoubleLinkedList& other);            // ���� ������.
    DoubleLinkedList& operator=(const DoubleLinkedList& rhs);   // �Ҵ� ������
    ~DoubleLinkedList();                                        // �Ҹ���

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front();
    const int& front() const;

    // ������ ��Ҹ� ��ȯ�Ѵ�.
    int& back();
    const int& back() const;

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // ����Ʈ�� ����ִٸ� end()�� ����.
    Node* begin();
    const Node* begin() const;

    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* end();
    const Node* end() const;

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* insert(Node* pos, int value);

    // pos ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    Node* erase(Node* pos);

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


