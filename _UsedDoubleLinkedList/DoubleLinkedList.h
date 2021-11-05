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
    DoubleLinkedList() = default;                               // 기본 생성자
    explicit DoubleLinkedList(size_t count);                    // count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
    DoubleLinkedList(const DoubleLinkedList& other);            // 복사 생성자.
    DoubleLinkedList& operator=(const DoubleLinkedList& rhs);   // 할당 연산자
    ~DoubleLinkedList();                                        // 소멸자

    // 첫 번째 요소를 반환한다.
    int& front();
    const int& front() const;

    // 마지막 요소를 반환한다.
    int& back();
    const int& back() const;

    // 시작 요소를 가리키는 반복자를 반환한다.
    // 리스트가 비어있다면 end()와 같다.
    Node* begin();
    const Node* begin() const;

    // 끝 다음 요소를 가리키는 반복자를 반환한다.
    Node* end();
    const Node* end() const;

    // pos 이전에 value를 삽입한다.
    // 삽입된 요소를 가리키는 반복자를 반환한다.
    Node* insert(Node* pos, int value);

    // pos 요소를 삭제한다.
    // 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
    // 아무 요소도 없으면 end()를 반환한다.
    Node* erase(Node* pos);

    void            push_front(int value);      // 시작에 value를 삽입한다.
    void            push_back(int value);       // 끝에 value를 삽입한다.
    void            pop_front();                // 시작 요소를 제거한다.
    void            pop_back();                 // 끝 요소를 제거한다.
    bool            empty() const;              // 컨테이너가 비었는지 판단한다.
    size_t          size() const;               // 리스트 안에 있는 요소의 개수를 반환한다.
    void            clear();                    // 컨테이너를 비워버린다.
    bool            contains(int value) const;  // 해당 value가 있는지 체크한다.

private:
    Node*           _end = new Node();
    Node*           _head = _end;
    size_t          _size = 0;
};


