// _UsedBinarySearch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <vector>
#include <numeric>
#include <random>
#include <ctime>

using namespace std;

int BinarySearch(const vector<int>& vec, int value)
{
    int s = 0, e = vec.size();

    while (s < e)
    {
        int m = (s + e) / 2;        // int m = s + (e - s) / 2;

		if (vec[m] == value) { return m; }
		else if (vec[m] < value) { s = m + 1; }
		else { e = m; }
    }

    return -1;
}

int BinarySearchR(const vector<int>& vec, int s, int e, int v)
{
	if (s >= e) { return -1; }
	int m = (s + e) / 2;

	if (vec[m] == v) { return m; }

	if (vec[m] < v) { return BinarySearchR(vec, m + 1, e, v); }
	else { return BinarySearchR(vec, s, m, v); }
}

int main()
{
	vector<int> vec(1'000'000);
	iota(vec.begin(), vec.end(), 1);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, vec.size());
	
	{
		int value = distrib(gen);
		printf("BinarySearch Test\n");
		printf("Value : %d, Index : %d\n", value, BinarySearch(vec, value));
	}
	
	clock_t start = clock();
	for (int i = 0; i < 1000; ++i)
	{
		int value = distrib(gen);
		BinarySearch(vec, value);
	}
	clock_t end = clock();
	printf("%f sec\n", (end - start) / static_cast<double>(CLOCKS_PER_SEC));
	
	puts("-------------------------------------------");
	
	{
		int value = distrib(gen);
		printf("BinarySearchR Test\n");
		printf("Value : %d, Index : %d\n", value, BinarySearchR(vec, 0, vec.size(), value));
	}
	
	start = clock();
	for (int i = 0; i < 1000; ++i)
	{
		int value = distrib(gen);
		BinarySearchR(vec, 0, vec.size(), value);
	}
	end = clock();
	printf("%f sec", (end - start) / static_cast<double>(CLOCKS_PER_SEC));
}
