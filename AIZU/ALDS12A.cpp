#include <iostream>
using namespace std;

void printlist(int lst[], size_t len){
	for(int i = 0; i < len - 1; i ++){
		cout << lst[i] << " ";
	}
	cout << lst[len - 1] << endl;
}

int bubbSort(int lst[], size_t len){
	bool flag = false;
	int j = len;
	int count = 0;

	do{
		for(int i = 1; i < j; i ++){
			if(lst[i - 1] > lst[i]){
				swap(lst[i - 1], lst[i]);
				flag = true;
				count += 1;
			}
		}

		j --;
	}while(flag && j >= 1);
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
	int count = bubbSort(st, sizeof(st) / sizeof(int));
	printlist(st, sizeof(st) / sizeof(int));
	cout << count << endl;
	return 0;
}