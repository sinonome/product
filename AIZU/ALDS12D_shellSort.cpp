#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int forgetind(int i, int x){
	int S = 1;
	int result = 0;

	while (result <= x){
		S *= i;
		result += 1;
	}
	return result - 1;
}
int power(int x, int i){
	int result = 1;
	for (int j = 0; j < i; j ++){
		result *= x;
	}
	return result;
}

void inserSort(int lst[], int n, int g){
	int select, j;

	for(int i = g; i < n; i ++){
		select = lst[i];
		j = i - g;

		while(j >= 0 && lst[j] > select){
			lst[j + g] = lst[j];
			j -= g;
		}

		lst[j + g] = select;
	}
}

void shellSort(int lst[], size_t len){
	int m = forgetind(3, 2 * len - 1);
	int G[m];

	for (int i = 0; i < m; i ++){
		G[i] = (power(3, i + 1) - 1) / 2;
	}

	for(int i = m - 1; i >= 0; i --){
		inserSort(lst, len, G[i]);
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
	shellSort(a, sizeof(a) / sizeof(int));
	for (auto x : a){
		cout << x << " ";
	}
	cout << ";;\n";
	return 0;
}