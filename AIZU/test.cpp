#include <iostream>
#include <vector>
#include <chrono>

int main()
{
    const int N = 1000*1000;
    std::vector<int> v;
    auto start = std::chrono::system_clock::now();      // 計測スタート時刻を保存
    for (int i = 0; i < N; ++i) {
        v.push_back(i);
    }
    auto end = std::chrono::system_clock::now();       // 計測終了時刻を保存
    auto dur = end - start;        // 要した時間を計算
    auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
    // 要した時間をミリ秒（1/1000秒）に変換して表示
    std::cout << msec << " milli sec \n";
    getchar();
    return 0;
}