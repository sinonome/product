#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
using namespace std;

int couonter = 0;
bool judge(int lst[], int len){
	for(int i = 0; i < len - 1; i ++){
		if(lst[i] <= lst[i + 1]) continue;
		else return true;
	}
	return false
	;
}

void bogoSort(int lst[], int len){
	random_device seed_gen;
	mt19937 engine(seed_gen());
	uniform_int_distribution<int> score(0, len - 1);
	while(!is_sorted(lst, lst + len)){
		swap(lst[score(engine)], lst[score(engine)]);
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