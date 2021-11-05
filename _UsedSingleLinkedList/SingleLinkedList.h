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
    SingleLinkedList();                                         // 기본 생성자
    explicit SingleLinkedList(size_t count);                    // count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
    SingleLinkedList(const SingleLinkedList& other);            // 복사 생성자.
    SingleLinkedList& operator=(const SingleLinkedList& rhs);   // 할당 연산자
    ~SingleLinkedList();                                        // 소멸자

    // 첫 번째 요소를 반환한다.
    int&        front();
    const int&  front() const;
    // 시작 전 요소를 가리키는 반복자를 반환한다.
    Node*       before_begin();
    const Node* before_begin() const;

    // 시작 요소를 가리키는 반복자를 반환한다.
    Node*       begin();
    const Node* begin() const;
    // 끝 다음 요소를 가리키는 반복자를 반환한다.
    Node*       end();
    const Node* end() const;

    // pos 다음에 value를 삽입한다.
    // 삽입된 요소를 가리키는 반복자를 반환한다.
    Node*       insert_after(Node* pos, int value);
    // pos 다음 요소를 삭제한다.
    // 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
    // 아무 요소도 없으면 end()를 반환한다.
    Node*       erase_after(Node* pos);
    
    void        push_front(int value);      // 시작 요소에 value를 삽입한다.
    void        pop_front();                // 시작 요소를 제거한다.
    bool        empty() const;              // 컨테이너가 비었는지 판단한다.
    void        clear();                    // 컨테이너를 비워버린다.
    bool        contains(int value) const;  // value가 있는지 없는지 판단한다.

private:
    Node* _head = new Node();
    Node* _end = new Node();
};


