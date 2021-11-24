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

	// 트리의 높이를 구한다.
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

	bool				empty() const { return _root == nullptr; }	// 트리가 비었는지 확인한다.
	size_t				size() const { return _size; }				// 트리의 크기를 반환한다.

	// 트리를 비운다.
	void				clear()
	{
		while (false == empty()) { erase(_root); }
	}

	// 트리에 값을 삽입한다.
	pair<Node*, bool>	insert(const T& value)
	{
		// root일 때
		if (empty())
		{
			_root = new Node(value);
			++_size;

			return make_pair(_root, true);
		}

		// 삽입할 위치를 찾는다.
		Node* inserted = _root;
		Node* parent = nullptr;

		while (inserted)
		{
			parent = inserted;

			if (inserted->Data == value) { return make_pair(inserted, false); }
			else if (inserted->Data < value) { inserted = inserted->Right; }
			else { inserted = inserted->Left; }
		}

		// 위치 찾았으면 노드를 생성한다.
		inserted = new Node(value, parent);

		if (parent->Data > value) { parent->Left = inserted; }
		else { parent->Right = inserted; }

		++_size;

		return make_pair(inserted, true);
	}

	// 트리에서 값을 삭제한다.
	void				erase(Node* pos)
	{
		// 아무것도 없을 때
		if (empty()) { return; }
		// pos가 root일 때
		if (pos->Parent == nullptr)
		{
			// 자식이 없을 때
			if (pos->Left == nullptr && pos->Right == nullptr)
			{
				_root = nullptr;

				delete pos;
				pos = nullptr;
				--_size;

				return;
			}
			// 자식이 하나일 때
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
			// 자식이 2개일 때
			Node* successor = pos->Left;

			while (successor->Right) { successor = successor->Right; }

			swap(pos->Data, successor->Data);

			erase(successor);

			return;
		}
		// 자식이 없을 때 => 단말 노드일 때
		if (pos->Left == nullptr && pos->Right == nullptr)
		{
			if (pos->Parent->Left == pos) { pos->Parent->Left = nullptr; }
			else { pos->Parent->Right = nullptr; }

			delete pos;
			pos = nullptr;
			--_size;

			return;
		}
		// 자식이 하나일 때
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
		// 자식이 2개일 때
		Node* successor = pos->Left;

		while (successor->Right) { successor = successor->Right; }

		swap(pos->Data, successor->Data);

		erase(successor);
	}
	size_t				erase(const T& value)
	{
		Node* removed = find(value);

		// value값을 가지는 노드가 없을 때 0을 반환.
		if (removed == nullptr) { return 0; }
		// 노드가 있을 때 제거 후 1을 반환.
		erase(removed);
		return 1;
	}

	// 트레이서 특정 값을 찾는다.
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

	// 순회
	void				traverseByPreOrder()	{ preOrderHelper(_root); }		// 현재 노드 -> Left -> Right
	void				traverseByInOrder()		{ inOrderHelper(_root); }		// Left -> 현재 노드 -> Right
	void				traverseByPostOrder()	{ postOrderHelper(_root); }		// Left -> Right -> 현재 노드
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