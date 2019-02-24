#include <iostream>
using namespace std;

int count = 0;
void printlist(int lst[], size_t len){
	for(int i = 0; i < len - 1; i ++){
		cout << lst[i] << " ";
	}
	cout << lst[len - 1] << endl;
}

int seleSort(int lst[], size_t len){
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
			count ++;
		}
		else{
			continue;
		}
	}
	return count;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int st[N];
	for (auto& i : st){
		cin >> i;
	}
	int count = seleSort(st, sizeof(st) / sizeof(int));
	printlist(st, sizeof(st) / sizeof(int));
	cout << count << endl;
	return 0;
}