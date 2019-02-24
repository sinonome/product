#include <iostream>
using namespace std;

int count = 0;

void printlist(int lst[], size_t len){
	for(size_t i = 0; i < len - 1; i ++){
		cout << lst[i] << " ";
	}
	cout << lst[len - 1] << endl;
}

void marge(int list[], size_t left, size_t mid, size_t right, size_t len){
	int i = 0;
	int j = 0;
	int k = 0;
	int n_1 = mid - left;
	int n_2 = right - mid;
	int B[right - left];

	while(i < n_1 && j < n_2){
		if(list[i + left] <= list[j + mid]){
			B[k] = list[i + left];
			i ++;
		}else{
			B[k] = list[j + mid];
			j ++;
		}
		k ++;
	}
	if(i == n_1){
		while(j < n_2){
			B[k] = list[j + mid];
			j ++;
			k ++;
		}
	}else{
		while(i < n_1){
			B[k] = list[i + left];
			i ++;
			k ++;
		}
	}
	count += k;

	for(size_t i = 0; i < right - left; i ++){
		list[left + i] = B[i];
	}
}

void margSort(int list[], size_t left, size_t right, size_t len){
	if(left +  1 < right){
		int mid((left + right) / 2);

		margSort(list, left, mid, len);
		margSort(list, mid, right, len);
		marge(list, left, mid, right, len);
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
	margSort(st, 0, sizeof(st) / sizeof(int), sizeof(st) / sizeof(int));
	printlist(st, sizeof(st) / sizeof(int));
	cout << count << endl;
	return 0;
}