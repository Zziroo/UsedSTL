#pragma once

#include "DoubleLinkedList.h"

class MyQueue
{
public:
    // �⺻ ������
    MyQueue() = default;

    // ���� ������
    MyQueue(const MyQueue& other)
        :_container{ other._container } {}

    // �Ҵ� ������
    MyQueue& operator=(const MyQueue& rhs)
    {
        if (this != &rhs)
        {
            _container = rhs._container;
        }

        return *this;
    }

    // �Ҹ���
    ~MyQueue() = default;

    // ť�� ù ��° ��ҿ� �����Ѵ�.
    int&            front() { return _container.front(); }
    const int&      front() const { return _container.front(); }

    // ť�� ������ ��ҿ� �����Ѵ�.
    int&            back() { return _container.back(); }
    const int&      back() const { return _container.back(); }

    // ť�� ������� Ȯ���Ѵ�.
    bool            empty() const { return _container.empty(); }

    // ť�� ũ�⸦ ��ȯ�Ѵ�.
    size_t          size() const { return _container.size(); }

    // ť�� �����͸� �����Ѵ�.
    void            push(int value) { _container.push_back(value); }

    // ť���� �����͸� ������.
    void            pop()
    {
        if (empty()) { return; }
        _container.pop_front();
    }

private:
    DoubleLinkedList        _container;
};