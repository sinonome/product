#include <iostream>
#include <random>
#include <ctime>
using namespace std;

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
	// cout << left << " " << mid << " " << right << endl;

	while(i < n_1 && j < n_2){
		if(list[i + left] <= list[j + mid]){
			B[k] = list[i + left];
			i ++;
		}else{
			B[k] = list[j + mid];
			j ++;
		}
		// cout << k << ":" << B[k] << endl;
		k ++;
	}
	if(i == n_1){
		while(j < n_2){
			B[k] = list[j + mid];
			// cout << k << ":" << B[k] << endl;
			j ++;
			k ++;
		}
	}else{
		while(i < n_1){
			B[k] = list[i + left];
			// cout << k << ":" << B[k] << endl;
			i ++;
			k ++;
		}
	}
	// cout << endl;

	for(size_t i = 0; i < right - left; i ++){
		list[left + i] = B[i];
		// cout << i << ":" << B[i] << endl;
	}
	// printlist(list, len);
}

void margSort(int list[], size_t left, size_t right, size_t len){
	if(left +  1 < right){
		// 要素が二つ以上なら分割していく、要素が一つになった瞬間終了
		int mid((left + right) / 2);

		// listを二分割してそれにたいしてマージを実施。
		margSort(list, left, mid, len);
		margSort(list, mid, right, len);
		marge(list, left, mid, right, len);
	}
}

int main(int argc, char const *argv[])
{
	int size = 8;
	int a[size];
	// 疑似乱数生成
	mt19937 mt(time(NULL));
	uniform_int_distribution<int> score(10, 1000);
	for (auto& x : a){
		x = score(mt);
		cout << x << " ";
	}
	cout << ";;\n\n";
	margSort(a, 0, sizeof(a) / sizeof(int), sizeof(a) / sizeof(int));
	for (auto x : a){
		cout << x << " ";
	}
	cout << ";;\n";
	return 0;
}