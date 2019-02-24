#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int partition(int A[], int p, int r){
	int x = A[r - 1];
	int i = p - 1;

	for(int j = p; j < r - 1; j ++){
		if(A[j] <= x){
			i ++;
			swap(A[i], A[j]);
		}
	}
	swap(A[++ i], A[r - 1]);
	return i;
}

void quicSort(int A[], int p, int r){
	if(p + 1 < r){
		int q = partition(A, p, r);
		quicSort(A, p, q);
		quicSort(A, q + 1, r);
	}
}

int main(int argc, char const *argv[])
{
	int size = 10;
	int a[size];
	// 疑似乱数生成
	mt19937 mt(time(NULL));
	uniform_int_distribution<int> score(10, 1000);
	for (auto& x : a){
		x = score(mt);
		cout << x << " ";
	}
	cout << ";;\n\n";

	quicSort(a, 0, sizeof(a) / sizeof(int));

	for (auto x : a){
		cout << x << " ";
	}
	cout << ";;\n";
	return 0;
}