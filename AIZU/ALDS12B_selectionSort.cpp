#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void seleSort(int lst[], size_t len){
	for(size_t i = 0; i < len - 1; i ++){
		int forgetmin(lst[i]);
		int forgeti(i);

		for(size_t j = i + 1; j < len; j ++){
			if (forgetmin > lst[j]){
				forgetmin = lst[j];
				forgeti = j;
			}
		}

		if(i != forgeti){
			swap(lst[i], lst[forgeti]);
		}
		else{
			continue;
		}
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