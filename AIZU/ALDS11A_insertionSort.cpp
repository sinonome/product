#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void inserSort(int lst[], size_t len){
	int key, pos;

	for(size_t i = 1; i < len; i ++){
		key = lst[i];
		pos = i - 1;

		while(pos >= 0 && lst[pos] > key){
			lst[pos + 1] = lst[pos];
			pos --;
		}
		lst[pos + 1] = key;
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
	inserSort(a, sizeof(a) / sizeof(int));
	for (auto x : a){
		cout << x << " ";
	}
	cout << ";;\n";
	return 0;
}