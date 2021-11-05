#pragma once

struct Node
{
public:
    Node(int data = 0, Node* next = nullptr)
        : Data{ data }, Next{ next } {}
    Node(const Node&) = delete;
    Node& operator=(const Node&) = delete;
    ~Node()
    {
        Data = 0;
        Next = nullptr;
    }

    int     Data = 0;
    Node*   Next = nullptr;
};

class SingleLinkedList
{
public:
    SingleLinkedList();                                         // �⺻ ������
    explicit SingleLinkedList(size_t count);                    // count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
    SingleLinkedList(const SingleLinkedList& other);            // ���� ������.
    SingleLinkedList& operator=(const SingleLinkedList& rhs);   // �Ҵ� ������
    ~SingleLinkedList();                                        // �Ҹ���

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int&        front();
    const int&  front() const;
    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*       before_begin();
    const Node* before_begin() const;

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*       begin();
    const Node* begin() const;
    // �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*       end();
    const Node* end() const;

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node*       insert_after(Node* pos, int value);
    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    // �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
    Node*       erase_after(Node* pos);
    
    void        push_front(int value);      // ���� ��ҿ� value�� �����Ѵ�.
    void        pop_front();                // ���� ��Ҹ� �����Ѵ�.
    bool        empty() const;              // �����̳ʰ� ������� �Ǵ��Ѵ�.
    void        clear();                    // �����̳ʸ� ���������.
    bool        contains(int value) const;  // value�� �ִ��� ������ �Ǵ��Ѵ�.

private:
    Node* _head = new Node();
    Node* _end = new Node();
};


