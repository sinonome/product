#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
using namespace std;

bool stoogeSort(int lst[], int i, int j){
	if(lst[j - 1] < lst[i]){
		swap(lst[i], lst[j - 1]);
	}
	if(j - i + 1 > 3){
		int t = (j - i) / 3;
		stoogeSort(lst, i, j - t);
		stoogeSort(lst, i + t, j);
		stoogeSort(lst, i, j - t);
	}
}

int main(int argc, char const *argv[])
{
	int size = 10;
	int a[size];
	// 疑似乱数生成
	mt19937 mt(time(NULL));
	uniform_int_distribution<int> score(1, 100);
	for (auto& x : a){
		x = score(mt);
		cout << x << " ";
	}
	cout << ";;\n\n";
	stoogeSort(a, 0, size);
	for (auto x : a){
		cout << x << " ";
	}
	cout << ";;\n";
	return 0;
}