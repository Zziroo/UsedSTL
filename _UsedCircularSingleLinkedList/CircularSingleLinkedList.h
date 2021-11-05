#pragma once

class CircularSingleLinkedList
{
public:
    struct Node
    {
        Node(int data = 0, Node* next = nullptr)
            : Data{ data }, Next{ next } { }
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node() = default;

        int   Data = 0;
        Node* Next = nullptr;
    };

public:
    // �⺻ ������
    CircularSingleLinkedList();

    // ���� ������
    CircularSingleLinkedList(const CircularSingleLinkedList& other);

    // �Ҵ� ������
    CircularSingleLinkedList& operator=(const CircularSingleLinkedList& rhs);

    // �Ҹ���
    ~CircularSingleLinkedList();

    // ù ��° ��Ҹ� ��ȯ�Ѵ�.
    int& front();
    const int& front() const;

    // ������ ��Ҹ� ��ȯ�Ѵ�.
    int& back();
    const int& back() const;

    // ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* before_head();
    const Node* before_head() const;

    // �� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* before_tail();
    const Node* before_tail() const;

    // ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* head();
    const Node* head() const;

    // �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* tail();
    const Node* tail() const;

    // pos ������ value�� �����Ѵ�.
    // ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* insert_after(Node* pos, int value);

    // pos ���� ��Ҹ� �����Ѵ�.
    // ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
    Node* erase_after(Node* pos);

    // ���� ��ҿ� value�� �����Ѵ�.
    void      push_front(int value);

    // ������ ��ҿ� value�� �����Ѵ�.
    void      push_back(int value);

    // ���� ��Ҹ� �����Ѵ�.
    void      pop_front();

    // ������ ��Ҹ� �����Ѵ�.
    void      pop_back();

    // �����̳ʰ� ������� �Ǵ��Ѵ�.
    bool      empty() const;

    // �����̳ʸ� ���������.
    void      clear();

    // �����̳ʿ� value�� �ִ��� Ȯ���Ѵ�.
    bool      contains(int value) const;
private:
    // � ����� �ʿ��ұ�?
};


