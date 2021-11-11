// _UsedSingleLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <forward_list>
#include "SingleLinkedList.h"

using namespace std;

int main()
{
	cout << "$ foward List $" << endl;

	forward_list<int> lst;
	forward_list<int> lst2(5);
	
	lst.push_front(1);
	// [1]
	lst.push_front(2);
	// [2] -> [1]
	lst.push_front(3);
	// [3] -> [2] -> [1]
	lst.pop_front();
	// [2] -> [1]
	
	// 2
	cout << lst.front() << endl;
	
	// 2 1
	for (int elem : lst)
	{
		cout << elem << ' ';
	}
	cout << endl;
	
	// [0] -> [0] -> [0] -> [0] -> [0]
	auto iter = lst2.insert_after(lst2.begin(), 3);
	// [0] -> [3] -> [0] -> [0] -> [0] -> [0] 
	//		         iter
	
	++iter;
	
	iter = lst2.insert_after(iter, 4);
	// [0] -> [3] -> [0] -> [4] -> [0] -> [0] -> [0]
	//						iter
	
	lst2.erase_after(iter);
	// [0] -> [3] -> [0] -> [4] -> [0] -> [0]
	
	for (int elem : lst2)
	{
		cout << elem << ' ';
	}
	cout << endl;
	
	cout << boolalpha << lst2.empty() << endl;
	
	forward_list<int> lst3(lst);
	
	for (int elem : lst3)
	{
		cout << elem << ' ';
	}
	cout << endl << endl;

	cout << "$ SingleLinkedList $ " << endl;
	SingleLinkedList myLst;
	SingleLinkedList myLst2(5);

	myLst.push_front(1);					// [1]
	myLst.push_front(2);					// [2] [1]
	myLst.push_front(3);					// [3] [2] [1]
	myLst.push_front(4);					// [4] [3] [2] [1]
	myLst.push_front(5);					// [5] [4] [3] [2] [1]
	myLst.pop_front();						// [4] [3] [2] [1]

	cout << myLst.front() << endl;			// [4]

	// 4 3 2 1
	for (int elem : myLst)
	{
		cout << elem << ' ';
	}
	cout << endl << endl;

	auto tempIter = myLst.begin()._p;
	cout << "제거할 요소 : " << tempIter->Data << endl;							// [4]
	cout << "제거 후 Data : " << myLst.erase_after(tempIter)._p->Data << endl;	// [3]
	cout << endl;

	auto iter2 = myLst2.insert_after(myLst2.begin(), 3);
	++iter2;
	iter2 = myLst2.insert_after(iter2, 4);
	myLst2.erase_after(iter2);

	for (int elem : myLst2)
	{
		cout << elem << ' ';
	}
	cout << endl;

	cout << boolalpha << myLst2.empty() << endl;

	SingleLinkedList myLst3(myLst);

	for (int elem : myLst3)
	{
		cout << elem << ' ';
	}
	cout << endl << endl;
}
