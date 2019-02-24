#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
using namespace std;

int couonter = 0;
void bogoSort(int lst[], int len){
	random_device seed_gen;
	mt19937 engine(seed_gen());
	while(!is_sorted(lst, lst + len)){
		shuffle(lst, lst + len, engine);
		couonter ++;
	}
}

int main(int argc, char const *argv[])
{
	int size = 5;
	int a[size];
	// 疑似乱数生成
	mt19937 mt(time(NULL));
	uniform_int_distribution<int> score(1, 100);
	for (auto& x : a){
		x = score(mt);
		cout << x << " ";
	}
	cout << ";;\n\n";
	bogoSort(a, size);
	for (auto x : a){
		cout << x << " ";
	}
	cout << ";;\n";
	cout << couonter << endl;
	return 0;
}