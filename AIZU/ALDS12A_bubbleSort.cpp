#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void bubbSort(int lst[], size_t len){
	bool flag = false;
	int j = len;

	do{
		for(int i = 1; i < j; i ++){
			if(lst[i - 1] > lst[i]){
				swap(lst[i - 1], lst[i]);
				flag = true;
			}
		}

		j --;
	}while(flag && j >= 1);
}

int main(int argc, char const *argv[])
{
	int size = 1;
	int a[size];
	// 疑似乱数生成
	mt19937 mt(time(NULL));
	uniform_int_distribution<int> score(1, 100);
	for (auto& x : a){
		x = score(mt);
		cout << x << " ";
	}
	cout << ";;\n\n";
	bubbSort(a, sizeof(a) / sizeof(int));
	for (auto x : a){
		cout << x << " ";
	}
	cout << ";;\n";
	return 0;
}