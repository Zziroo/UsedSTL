// _UsedDoubleLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include "DoubleLinkedList.h"
#include "TemplateDoubleLinkedList.h"

using namespace std;

int main()
{
	cout << "$ list $" << endl;
	list<int> lst;
	lst.push_front(1);
	lst.push_back(2);
	lst.push_front(3);

	cout << lst.front() << endl;

	for (int elem : lst)
	{
		cout << elem << ' ';
	}
	cout << endl << endl;

	cout << "$ DoubleLinkedList $" << endl;
	DoubleLinkedList myLst;
	myLst.push_front(1);
	myLst.push_back(2);
	myLst.push_front(3);

	cout << myLst.front() << endl;

	for (int elem : myLst)
	{
		cout << elem << ' ';
	}
	cout << endl << endl;

	cout << "$ TemplateDoubleLinkedList $" << endl;
	TemplateDoubleLisnked<int> myTemplateLst;
	myTemplateLst.push_front(1);
	myTemplateLst.push_back(2);
	myTemplateLst.push_front(3);

	cout << myTemplateLst.front() << endl;

	for (int elem : myTemplateLst)
	{
		cout << elem << ' ';
	}
	cout << endl << endl;
}
