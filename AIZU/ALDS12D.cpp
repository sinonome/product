#include <iostream>
using namespace std;

int count = 0;
void printlist(int lst[], size_t len){
	for(size_t i = 0; i < len - 1; i ++){
		cout << lst[i] << " ";
	}
	cout << lst[len - 1] << endl;
}

int forgetind(int i, int x){
	int S = 1;
	int result = 0;

	while (S <= x){
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
			count ++;
		}

		lst[j + g] = select;
	}
}

void shellSort(int lst[], size_t len){
	int m = forgetind(3, 2 * len + 1);
	int G[m];
	cout << m << endl;

	for (int i = m - 1; i >= 0; i --){
		G[m - i - 1] = (power(3, i + 1) - 1) / 2;
	}
	printlist(G, m);

	for(int i = 0; i < m; i ++){
		inserSort(lst, len, G[i]);
	}
}


int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int st[N];
	for (auto& i : st){
		cin >> i;
	}
	shellSort(st, sizeof(st) / sizeof(int));
	cout << count << endl;
	for(auto x:st){
		cout << x << endl;
	}
	return 0;
}