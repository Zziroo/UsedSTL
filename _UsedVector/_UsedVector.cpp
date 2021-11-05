// _UsedVector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include "MyVector.h"
#include "TemplateVector.h"

using namespace std;

int main()
{
	cout << "$ vector<int> $" << endl;
	vector<int> vec;

	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	for (int i = 0; i < vec.size(); ++i) { cout << vec[i] << " "; }
	cout << endl;

	vec.pop_back();

	cout << boolalpha << vec.empty() << endl;
	cout << "Cap : " << vec.capacity() << endl;
	vec.reserve(7);
	cout << "New Cap : " << vec.capacity() << endl;
	vec.reserve(16);
	cout << "New Cap : " << vec.capacity() << endl;

	try { vec.at(5); }
	catch (std::out_of_range& e) { cout << e.what() << endl << endl; }

	cout << "$ MyVector $" << endl;
	MyVector myVec;

	myVec.push_back(0);
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);
	myVec.push_back(4);
	myVec.push_back(5);

	for (int i = 0; i < myVec.size(); ++i) { cout << myVec[i] << " "; }
	cout << endl;

	myVec.pop_back();

	cout << boolalpha << myVec.empty() << endl;
	cout << "Cap : " << myVec.capacity() << endl;
	myVec.reserve(7);
	cout << "New Cap : " << myVec.capacity() << endl;
	myVec.reserve(16);
	cout << "New Cap : " << myVec.capacity() << endl;

	try { myVec.at(5); }
	catch (std::out_of_range& e) { cout << e.what() << endl << endl; }

	cout << "$ TemplateVector<int> $" << endl;
	TemplateVector<int> vecTemplate;

	vecTemplate.push_back(0);
	vecTemplate.push_back(1);
	vecTemplate.push_back(2);
	vecTemplate.push_back(3);
	vecTemplate.push_back(4);
	vecTemplate.push_back(5);

	for (int i = 0; i < vecTemplate.size(); ++i) { cout << vecTemplate[i] << " "; }
	cout << endl;

	vecTemplate.pop_back();

	cout << boolalpha << vecTemplate.empty() << endl;
	cout << "Cap : " << vecTemplate.capacity() << endl;
	vecTemplate.reserve(7);
	cout << "New Cap : " << vecTemplate.capacity() << endl;
	vecTemplate.reserve(16);
	cout << "New Cap : " << vecTemplate.capacity() << endl;

	try { vecTemplate.at(5); }
	catch (std::out_of_range& e) { cout << e.what() << endl; }
}
