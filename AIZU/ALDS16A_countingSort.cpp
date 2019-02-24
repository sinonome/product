#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int max(int lst[], size_t len){
	int result = lst[0];

	for(size_t i = 1; i < len; i ++){
		if(result < lst[i]){
			result = lst[i];
		}
	}

	return result;
}

void counSort(int lst[], int B[], size_t len, int k){
	int C[k + 1];
	int offset[k + 1];
	for(auto& x:C) x = 0;

	for(size_t i = 0; i < len; i ++){
		C[lst[i]] ++;
	}

	offset[0] = 0;
	for(int i = 1;i <= k; i ++){
		offset[i] = offset[i - 1] + C[i - 1];
	}

	for(int i = 0; i < len; i ++){
		int target = lst[i];
		B[offset[target]] = target;
		offset[target] ++;
	}
}

int main(int argc, char const *argv[])
{
	int size = 10;
	int a[size], b[size];
	// 疑似乱数生成
	mt19937 mt(time(NULL));
	uniform_int_distribution<int> score(10, 1000);
	for (auto& x : a){
		x = score(mt);
		cout << x << " ";
	}
	cout << ";;\n\n";
	counSort(a, b, sizeof(a) / sizeof(int), max(a, sizeof(a) / sizeof(int)));
	for (auto x : b){
		cout << x << " ";
	}
	cout << ";;\n";
	return 0;
}