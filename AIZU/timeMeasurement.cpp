#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

void seleSort(int lst[], size_t len){
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
		}
		else{
			continue;
		}
	}
}

auto timeMeasu(int size){
	mt19937 mt(time(NULL));
	uniform_int_distribution<int> score(10, 1000);

	// 並べ替えるリストの初期化
	int list[size];

	for(auto& x:list){
		x = score(mt);
	}

	auto startTime = system_clock::now();	// 計測スタート

	// 計測したいproccess
	seleSort(list, sizeof(list) / sizeof(int));

	auto endTime = system_clock::now();
	auto t = endTime - startTime;
	return duration_cast<milliseconds>(t).count();
}

void mainprocces(int times = 100, int size = 10)
{
	double sec = 0;
	// 計測合計を計算

	for(int j = 0; j < times; j ++){
		auto result = timeMeasu(size);
		sec += result;
	}

	cout << size << " " << sec << endl;
}

int main(int argc, char const *argv[])
{
	int a = 100;
	int b = 1000;
	int times = 10000;
	for(int i = a; i <= b; i ++){
		mainprocces(times, i);
	}
	return 0;
}