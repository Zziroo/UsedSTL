// _UsedStack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	cout << "$ Stack &" << endl;
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	while (false == st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;

	vector<int> vec = { 1,2,3,4,5,6,7,8,9,10 };
	stack<int, vector<int>> st2(vec);
	while (false == st2.empty())
	{
		cout << st2.top() << " ";
		st2.pop();
	}
	cout << endl << endl;
}
