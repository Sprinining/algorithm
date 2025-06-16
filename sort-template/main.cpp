#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "sort.h"
using namespace std;
using namespace my_sort;     // 使用你自定义的 namespace
using namespace std::chrono; // 用于计时

// 测试参数
const int TEST_TIMES = 1000; // 测试次数
const int MAX_LEN = 100;     // 每个数组最大长度
const int MAX_VAL = 100;     // 每个元素最大值（含负数）

// 生成一个长度随机、数值随机的整数数组（含负数）
vector<int> generateRandomArray() {
    int len = rand() % MAX_LEN;
    vector<int> arr(len);
    for (int i = 0; i < len; ++i) {
        arr[i] = rand() % (2 * MAX_VAL + 1) - MAX_VAL; // 范围：[-MAX_VAL, MAX_VAL]
    }
    return arr;
}

// 判断两个数组是否完全相等
bool isEqual(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    srand(time(nullptr)); // 初始化随机数种子
    Sort sorter;          // 自定义排序类实例
    bool success = true;  // 标志：是否所有测试都通过

    long long mySortTotalTime = 0;  // 自定义排序总耗时（单位：微秒）
    long long stdSortTotalTime = 0; // std::sort 总耗时（单位：微秒）

    for (int i = 0; i < TEST_TIMES; ++i) {
        vector<int> arr = generateRandomArray(); // 原始数组
        vector<int> arrCopy = arr;               // 拷贝数组作为对照组

        // 计时：排序
        auto start1 = high_resolution_clock::now();
        sorter.bubbleSort(arr); // 调用自己写的排序
        auto end1 = high_resolution_clock::now();
        mySortTotalTime += duration_cast<microseconds>(end1 - start1).count();

        // 计时：标准库排序
        auto start2 = high_resolution_clock::now();
        sort(arrCopy.begin(), arrCopy.end());
        auto end2 = high_resolution_clock::now();
        stdSortTotalTime += duration_cast<microseconds>(end2 - start2).count();

        // 正确性验证
        if (!isEqual(arr, arrCopy)) {
            success = false;
            cout << "❌ 排序出错！" << endl;
            cout << "原始数组：";
            for (int x : arrCopy)
                cout << x << " ";
            cout << "\n你的排序：";
            for (int x : arr)
                cout << x << " ";
            cout << "\n";
            break;
        }
    }

    // 输出最终统计结果
    if (success) {
        cout << "✅ 所有测试通过！" << endl;
        cout << "✨ 总测试次数：" << TEST_TIMES << endl;
        cout << "🕒 你的排序总耗时（microseconds）：\t" << mySortTotalTime << endl;
        cout << "🕒 std::sort 总耗时（microseconds）：\t" << stdSortTotalTime << endl;
        cout << "📊 平均每次：你 = " << (mySortTotalTime / TEST_TIMES) << "us，std::sort = " << (stdSortTotalTime / TEST_TIMES) << "us" << endl;
    }

    return 0;
}
