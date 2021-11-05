// _UsedDoubleLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
	cout << "$ list $" << endl;
	list<int> list;
	list.push_front(1);
	list.push_back(2);
	list.push_front(3);

	cout << list.front() << endl;

	for (int elem : list)
	{
		cout << elem << ' ';
	}
	cout << endl << endl;

	cout << "$ DoubleLinkedList $" << endl;
	DoubleLinkedList myList;
	myList.push_front(1);
	myList.push_back(2);
	myList.push_front(3);

	cout << myList.front() << endl;

	for (int elem : myList)
	{
		cout << elem << ' ';
	}
	cout << endl;
}
