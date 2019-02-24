#include <iostream>
using namespace std;

int partition(int A[], int p, int r){
	int x = A[r - 1];
	int i = p - 1;

	for(int j = 0; j < r - 1; j ++){
		if(A[j] <= x){
			i ++;
			swap(A[i], A[j]);
		}
	}
	swap(A[++ i], A[r - 1]);
	return i;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int st[N];
	for(auto& x:st){
		cin >> x;
	}
	size_t len = sizeof(st) / sizeof(int);
	int i = partition(st, 0, len);
	for (size_t j = 0; j < len; j ++){
		if(i != j){
			cout << st[j];
		}else{
			cout << "[" << st[j] << "]";
		}
		if(j == len - 1){
			cout << endl;
		}else{
			cout << " ";
		}
	}
	return 0;
}