// _UsedHeap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include "MyHeap.h"

using namespace std;

int main()
{
	const auto data = { 77, 18, 58, 28, 12, 17, 19, 9, 44, 69 };
	priority_queue<int> pq;

	for (int d : data) { pq.push(d); }

	// 77 69 58 44 28 19 17 12 9
	while (false == pq.empty())
	{
		int d = pq.top();
		pq.pop();

		cout << d << ' ';
	}
	puts("");
	puts("-----------------------------");

	MyHeap mH;

	for (int d : data) { mH.push(d); }

	// 77 69 58 44 28 19 17 12 9
	while (false == mH.empty())
	{
		int d = mH.top();
		mH.pop();

		cout << d << ' ';
	}
	puts("");
}

