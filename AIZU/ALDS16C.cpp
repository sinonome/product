#include <iostream>
#include <string>
using namespace std;

int partition(int A[], char B[], int C[], int p, int r){
	int x = A[r - 1];
	int i = p - 1;

	for(int j = p; j < r - 1; j ++){
		if(A[j] <= x){
			i ++;
			swap(A[i], A[j]);
			swap(B[i], B[j]);
			swap(C[i], C[j]);
		}
	}
	swap(A[++ i], A[r - 1]);
	swap(B[i], B[r - 1]);
	swap(C[i], C[r - 1]);
	return i;
}

void quicSort(int A[], char B[], int C[], int p, int r){
	if(p + 1 < r){
		int q = partition(A, B, C, p, r);
		quicSort(A, B, C, p, q);
		quicSort(A, B, C, q + 1, r);
	}
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int a[N];
	char b[N];
	int c[N];
	for(int i = 0; i < N; i ++){
		cin >> b[i] >> a[i];
		c[i] = i;
	}

	quicSort(a, b, c, 0, N);

	bool flag = true;
	for(int i = 0; i < N - 1; i ++){
		if(a[i] == a[i + 1] && c[i] > c[i + 1]){
			flag = false;
			break;
		}else{
			continue;
		}
	}

	cout << (flag ? "Stable":"Not stable") << endl;

	for(int i = 0; i < N; i ++){
		cout << b[i] << " " << a[i] << endl;
	}
	return 0;
}
