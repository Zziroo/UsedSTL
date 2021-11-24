#pragma once

#include <iostream>
#include <utility>
#include <queue>

using namespace std;

template<typename T>
class TemplateBinarySearchTree
{
public:
	struct Node
	{
		Node(const T& data = {}, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr)
			:Data{ data }, Parent{ parent }, Left{ left }, Right{ right } {}
		Node(const Node&) = default;
		Node& operator=(const Node&) = default;
		~Node()
		{
			Parent = nullptr;
			Left = nullptr;
			Right = nullptr;
		}

		T		Data = 0;
		Node*	Parent = nullptr;
		Node*	Left = nullptr;
		Node*	Right = nullptr;
	};

public:
	TemplateBinarySearchTree() = default;
	~TemplateBinarySearchTree() { clear(); }

	// Ʈ���� ���̸� ���Ѵ�.
	int					heightBFS() const
	{
		if (empty()) { return -1; }

		queue<Node*> q;
		q.push(_root);

		int h = -1;

		while (false == q.empty())
		{
			size_t sz = q.size();
			for (size_t i = 0; i < sz; ++i)
			{
				Node* node = q.front();
				q.pop();

				if (node->Left) { q.push(node->Left); }
				if (node->Right) { q.push(node->Right); }
			}
			++h;
		}

		return h;
	}
	int					heightDFS() const { return heightDFSHelper(_root); }

	bool				empty() const { return _root == nullptr; }	// Ʈ���� ������� Ȯ���Ѵ�.
	size_t				size() const { return _size; }				// Ʈ���� ũ�⸦ ��ȯ�Ѵ�.

	// Ʈ���� ����.
	void				clear()
	{
		while (false == empty()) { erase(_root); }
	}

	// Ʈ���� ���� �����Ѵ�.
	pair<Node*, bool>	insert(const T& value)
	{
		// root�� ��
		if (empty())
		{
			_root = new Node(value);
			++_size;

			return make_pair(_root, true);
		}

		// ������ ��ġ�� ã�´�.
		Node* inserted = _root;
		Node* parent = nullptr;

		while (inserted)
		{
			parent = inserted;

			if (inserted->Data == value) { return make_pair(inserted, false); }
			else if (inserted->Data < value) { inserted = inserted->Right; }
			else { inserted = inserted->Left; }
		}

		// ��ġ ã������ ��带 �����Ѵ�.
		inserted = new Node(value, parent);

		if (parent->Data > value) { parent->Left = inserted; }
		else { parent->Right = inserted; }

		++_size;

		return make_pair(inserted, true);
	}

	// Ʈ������ ���� �����Ѵ�.
	void				erase(Node* pos)
	{
		// �ƹ��͵� ���� ��
		if (empty()) { return; }
		// pos�� root�� ��
		if (pos->Parent == nullptr)
		{
			// �ڽ��� ���� ��
			if (pos->Left == nullptr && pos->Right == nullptr)
			{
				_root = nullptr;

				delete pos;
				pos = nullptr;
				--_size;

				return;
			}
			// �ڽ��� �ϳ��� ��
			if (pos->Left == nullptr)
			{
				_root = pos->Right;
				_root->Parent = nullptr;

				delete pos;
				pos = nullptr;
				--_size;

				return;
			}
			else if (pos->Right == nullptr)
			{
				_root = pos->Left;
				_root->Parent = nullptr;

				delete pos;
				pos = nullptr;
				--_size;

				return;
			}
			// �ڽ��� 2���� ��
			Node* successor = pos->Left;

			while (successor->Right) { successor = successor->Right; }

			swap(pos->Data, successor->Data);

			erase(successor);

			return;
		}
		// �ڽ��� ���� �� => �ܸ� ����� ��
		if (pos->Left == nullptr && pos->Right == nullptr)
		{
			if (pos->Parent->Left == pos) { pos->Parent->Left = nullptr; }
			else { pos->Parent->Right = nullptr; }

			delete pos;
			pos = nullptr;
			--_size;

			return;
		}
		// �ڽ��� �ϳ��� ��
		if (pos->Left == nullptr)
		{
			if (pos->Parent->Left == pos) { pos->Parent->Left = pos->Right; }
			else { pos->Parent->Right = pos->Right; }

			pos->Right->Parent = pos->Parent;

			delete pos;
			pos = nullptr;
			--_size;

			return;
		}
		else if (pos->Right == nullptr)
		{
			if (pos->Parent->Left == pos) { pos->Parent->Left = pos->Left; }
			else { pos->Parent->Right = pos->Left; }

			pos->Left->Parent = pos->Parent;

			delete pos;
			pos = nullptr;
			--_size;

			return;
		}
		// �ڽ��� 2���� ��
		Node* successor = pos->Left;

		while (successor->Right) { successor = successor->Right; }

		swap(pos->Data, successor->Data);

		erase(successor);
	}
	size_t				erase(const T& value)
	{
		Node* removed = find(value);

		// value���� ������ ��尡 ���� �� 0�� ��ȯ.
		if (removed == nullptr) { return 0; }
		// ��尡 ���� �� ���� �� 1�� ��ȯ.
		erase(removed);
		return 1;
	}

	// Ʈ���̼� Ư�� ���� ã�´�.
	Node* find(const T& value) { return const_cast<Node*>(static_cast<const TemplateBinarySearchTree&>(*this).find(value)); }
	const Node* find(const T& value) const
	{
		const Node* result = _root;

		while (result)
		{
			if (result->Data == value) { return result; }
			else if (result->Data < value) { result = result->Right; }
			else { result = result->Left; }
		}

		return result;
	}

	// ��ȸ
	void				traverseByPreOrder()	{ preOrderHelper(_root); }		// ���� ��� -> Left -> Right
	void				traverseByInOrder()		{ inOrderHelper(_root); }		// Left -> ���� ��� -> Right
	void				traverseByPostOrder()	{ postOrderHelper(_root); }		// Left -> Right -> ���� ���
	void				traverseByLevelOrder()									// Queue
	{
		if (empty()) { return; }

		queue<Node*> q;
		q.push(_root);

		size_t h = 0;

		while (false == q.empty())
		{
			cout << "Level " << h << " : ";
			size_t sz = q.size();
			for (size_t i = 0; i < sz; ++i)
			{
				Node* node = q.front();
				q.pop();

				cout << node->Data << ' ';

				if (node->Left) { q.push(node->Left); }
				if (node->Right) { q.push(node->Right); }
			}
			++h;
		}
	}

private:
	int					heightDFSHelper(const Node* node) const
	{
		if (node == nullptr) { return -1; }

		int left = heightDFSHelper(node->Left) + 1;
		int right = heightDFSHelper(node->Right) + 1;

		return max(left, right);
	}

	void				preOrderHelper(const Node* node)
	{
		if (node == nullptr) { return; }

		cout << node->Data << ' ';
		preOrderHelper(node->Left);
		preOrderHelper(node->Right);
	}
	void				inOrderHelper(const Node* node)
	{
		if (node == nullptr) { return; }

		preOrderHelper(node->Left);
		cout << node->Data << ' ';
		preOrderHelper(node->Right);
	}
	void				postOrderHelper(const Node* node)
	{
		if (node == nullptr) { return; }

		preOrderHelper(node->Left);
		preOrderHelper(node->Right);
		cout << node->Data << ' ';
	}

private:
	Node*				_root = nullptr;
	size_t				_size = 0;
};