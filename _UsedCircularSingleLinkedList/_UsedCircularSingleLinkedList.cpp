// _UsedCircularSingleLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "CircularSingleLinkedList.h"

using namespace std;

int main()
{
	cout << "$ CircularSingleLinkedList $" << endl;
	CircularSingleLinkedList lst;

	lst.push_back(1);		// [1]
	lst.push_front(3);		// [3] [1]
	lst.push_front(2);		// [2] [3] [1]
	lst.push_back(4);		// [2] [3] [1] [4]

	cout << "Front : " << lst.front() << "\t" << "Back : " << lst.back() << endl;
	auto iter = lst.head();
	do
	{
		cout << iter->Data << " -> ";

		iter = iter->Next;
	} while (iter != lst.head());
	cout << lst.tail()->Next->Data << endl;
	cout << endl;

	lst.pop_back();			// [2] [3] [1]
	lst.pop_front();		// [3] [1]
	cout << "Front : " << lst.front() << "\t" << "Back : " << lst.back() << endl;
	iter = lst.head();
	do
	{
		cout << iter->Data << " -> ";

		iter = iter->Next;
	} while (iter != lst.head());
	cout << lst.tail()->Next->Data << endl;
}
