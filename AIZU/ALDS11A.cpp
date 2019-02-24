#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void printlist(int lst[], size_t len){
	for(int i = 0; i < len - 1; i ++){
		cout << lst[i] << " ";
	}
	cout << lst[len - 1] << endl;
}

void inserSort(int lst[], size_t len){
	int select, j;

	for(size_t i = 1; i < len; i ++){
		select = lst[i];
		j = i - 1;

		while(j >= 0 && lst[j] > select){
			swap(lst[j], lst[j + 1]);
			j --;
		}
		printlist(lst, len);
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
	printlist(st, sizeof(st) / sizeof(int));
	inserSort(st, sizeof(st) / sizeof(int));
	return 0;
}