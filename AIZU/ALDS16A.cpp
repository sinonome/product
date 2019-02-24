#include <iostream>
using namespace std;

void printlist(int lst[], size_t len){
	for(size_t i = 0; i < len - 1; i ++){
		cout << lst[i] << " ";
	}
	cout << lst[len - 1] << endl;
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
	int N;
	cin >> N;
	int st[N], result[N];
	int m = 0;
	for (auto& i : st){
		cin >> i;
		if (m < i){
			m = i;
		}
	}
	counSort(st, result, sizeof(st) / sizeof(int), m);
	printlist(result, sizeof(result) / sizeof(int));
	return 0;
}