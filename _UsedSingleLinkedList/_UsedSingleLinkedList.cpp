// _UsedSingleLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <forward_list>
#include "SingleLinkedList.h"

using namespace std;

int main()
{
	cout << "$ foward List $" << endl;

	forward_list<int> list;
	forward_list<int> list2(5);
	
	list.push_front(1);
	// [1]
	list.push_front(2);
	// [2] -> [1]
	list.push_front(3);
	// [3] -> [2] -> [1]
	list.pop_front();
	// [2] -> [1]
	
	// 2
	cout << list.front() << endl;
	
	// 2 1
	for (int elem : list)
	{
		cout << elem << ' ';
	}
	cout << endl;
	
	// [0] -> [0] -> [0] -> [0] -> [0]
	auto iter = list2.insert_after(list2.begin(), 3);
	// [0] -> [3] -> [0] -> [0] -> [0] -> [0] 
	//		         iter
	
	++iter;
	
	iter = list2.insert_after(iter, 4);
	// [0] -> [3] -> [0] -> [4] -> [0] -> [0] -> [0]
	//						iter
	
	list2.erase_after(iter);
	// [0] -> [3] -> [0] -> [4] -> [0] -> [0]
	
	for (int elem : list2)
	{
		cout << elem << ' ';
	}
	cout << endl;
	
	cout << boolalpha << list2.empty() << endl;
	
	forward_list<int> list3(list);
	
	for (int elem : list3)
	{
		cout << elem << ' ';
	}
	cout << endl << endl;

	cout << "$ SingleLinkedList $ " << endl;
	SingleLinkedList myList;
	SingleLinkedList myList2(5);

	myList.push_front(1);
	myList.push_front(2);
	myList.push_front(3);
	myList.pop_front();

	cout << myList.front() << endl;
	for (int elem : myList)
	{
		cout << elem << ' ';
	}
	cout << endl;

	auto iter2 = myList2.insert_after(myList2.begin(), 3);
	++iter2;
	iter2 = myList2.insert_after(iter2, 4);
	myList2.erase_after(iter2);

	for (int elem : myList2)
	{
		cout << elem << ' ';
	}
	cout << endl;

	cout << boolalpha << myList2.empty() << endl;

	SingleLinkedList myList3(myList);

	for (int elem : myList3)
	{
		cout << elem << ' ';
	}
	cout << endl << endl;
}
