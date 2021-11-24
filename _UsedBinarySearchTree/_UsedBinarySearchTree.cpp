// _UsedBinarySearchTree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <set>
#include "BinarySearchTree.h"
#include "TemplateBinarySearchTree.h"


using namespace std;

int main()
{
	set<int> set = { 8, 3, 2, 5, 4, 10, 14, 11, 16 };

	// 2, 3, 4, 5, 8, 10, 11, 14, 16
	for (int data : set)
	{
		cout << data << ' ';
	}
	cout << "\n";

	if (set.end() != set.find(2)) { cout << "Found 2\n"; }

	if (set.end() == set.find(12)) { cout << "Not Found 12\n"; }

	// 9
	cout << "Size : " << set.size() << "\n";

	auto iter = set.begin();	// 2
	++iter;						// 3
	++iter;						// 4

	set.erase(iter);			// 4를 삭제.

	// 8
	cout << "Size : " << set.size() << "\n";

	if (set.end() == set.find(4)) { cout << "Not Found 4\n"; }

	// false
	cout << boolalpha << set.empty() << "\n";

	set.clear();

	// true
	cout << set.empty() << "\n";

	puts("-------------------------------------");

	BinarySearchTree mySet;

	mySet.insert(8);
	mySet.insert(3);
	mySet.insert(2);
	mySet.insert(5);
	mySet.insert(4);
	mySet.insert(10);
	mySet.insert(14);
	mySet.insert(11);
	mySet.insert(16);

	if (mySet.find(2)) { cout << "Found 2\n"; }

	if (mySet.find(12) == nullptr) { cout << "Not Found 12\n"; }

	// 9
	cout << "Size : " << mySet.size() << "\n";

	mySet.erase(4);

	// 8
	cout << "Size : " << mySet.size() << "\n";

	if (mySet.find(4) == nullptr) { cout << "Not Found 4\n"; }

	// 8 3 2 5 10 14 11 16
	mySet.traverseByPreOrder();
	puts("");
	// 2 3 5 8 10 11 14 16
	mySet.traverseByInOrder();
	puts("");
	// 2 5 3 11 16 14 10 8
	mySet.traverseByPostOrder();
	puts("");
	// 8 3 10 2 5 14 11 16
	mySet.traverseByLevelOrder();
	puts("");

	// 3
	cout << "HeightBFS : " << mySet.heightBFS() << "\t" << "HeightDFS : " << mySet.heightDFS() << "\n";

	// false
	cout << mySet.empty() << "\n";

	mySet.clear();

	// true
	cout << mySet.empty() << "\n";

	puts("-------------------------------------");

	TemplateBinarySearchTree<int> myTemplateSet;

	myTemplateSet.insert(8);
	myTemplateSet.insert(3);
	myTemplateSet.insert(2);
	myTemplateSet.insert(5);
	myTemplateSet.insert(4);
	myTemplateSet.insert(10);
	myTemplateSet.insert(14);
	myTemplateSet.insert(11);
	myTemplateSet.insert(16);

	if (myTemplateSet.find(2)) { cout << "Found 2\n"; }

	if (myTemplateSet.find(12) == nullptr) { cout << "Not Found 12\n"; }

	// 9
	cout << "Size : " << myTemplateSet.size() << "\n";

	myTemplateSet.erase(4);

	// 8
	cout << "Size : " << myTemplateSet.size() << "\n";

	if (myTemplateSet.find(4) == nullptr) { cout << "Not Found 4\n"; }

	// 8 3 2 5 10 14 11 16
	myTemplateSet.traverseByPreOrder();
	puts("");
	// 2 3 5 8 10 11 14 16
	myTemplateSet.traverseByInOrder();
	puts("");
	// 2 5 3 11 16 14 10 8
	myTemplateSet.traverseByPostOrder();
	puts("");
	// 8 3 10 2 5 14 11 16
	myTemplateSet.traverseByLevelOrder();
	puts("");

	// 3
	cout << "HeightBFS : " << myTemplateSet.heightBFS() << "\t" << "HeightDFS : " << myTemplateSet.heightDFS() << "\n";

	// false
	cout << myTemplateSet.empty() << "\n";

	myTemplateSet.clear();

	// true
	cout << myTemplateSet.empty() << "\n";
}
