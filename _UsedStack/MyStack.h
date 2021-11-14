#pragma once

#include "MyVector.h"

class MyStack
{
public:
    // �⺻ ������
    MyStack() = default;

    // ���� ������
    MyStack(const MyStack& other)
        :_container{ other._container } {}

    // �Ҵ� ������
    MyStack& operator=(const MyStack& rhs)
    {
        if (this != &rhs)
        {
            _container = rhs._container;
        }

        return *this;
    }

    // �Ҹ���
    ~MyStack() = default;

    // ������ �� �� ��ҿ� �����Ѵ�.
    int&            top() { return _container.back(); }
    const int&      top() const { return _container.back(); }

    // ������ ������� �˻��Ѵ�.
    bool            empty() const { return _container.empty(); }

    // ������ ũ�⸦ ��ȯ�Ѵ�.
    size_t          size() const { return _container.size(); }

    // ���ÿ� �����͸� �����Ѵ�.
    void            push(int value) { _container.push_back(value); }

    // ���ÿ��� �����͸� �����Ѵ�.
    void            pop() { _container.pop_back(); }

private:
    MyVector        _container;
};