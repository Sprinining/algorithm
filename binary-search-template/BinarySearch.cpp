#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
  public:
    // 区间 [left, size - 1] 上找目标值出现的下标
    static int binarySearch(vector<int>& arr, int target, int left, int right) {
        int l = left, r = right, m;

        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (target == arr[m]) {
                return m;
            } else if (target < arr[m]) {
                r = m - 1; // r 更新之后，r 右边必然都大于 target (不更新不保证大于)
            } else {
                l = m + 1; // l 更新之后，l 左边必然都小于 target
            }
        }

        return -1; // 查找失败时 l = r + 1
    }

    // 找第一个 ≥ target
    static int lowerBound(vector<int>& arr, int target, int left, int right) {
        int l = left, r = right, m;

        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (target > arr[m]) {
                l = m + 1; // l 更新之后，l 左边必然都小于 target
            } else {
                r = m - 1; // r 更新之后，r 右边必然都大于等于 target
            }
        }

        return l; // 循环结束时 l = r + 1
    }

    // 找第一个 > target
    static int upperBound(vector<int>& arr, int target, int left, int right) {
        int l = left, r = right, m;

        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (target >= arr[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }

    // 找最后一个 ≤ target
    static int lastLE(vector<int>& arr, int target, int left, int right) {
        int l = left, r = right, m;

        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (target >= arr[m]) { // 即使等于 l 也右移，这样小于等于的就都在 l 左边了，循环结束时，r 就在 l - 1 的位置
                l = m + 1;          // l 更新之后，l 左边必然都小于等于 target
            } else {
                r = m - 1; // r 更新之后，r 右边必然都大于 target
            }
        }

        return r;
    }

    // 	找最后一个 < target
    static int lastLT(vector<int>& arr, int target, int left, int right) {
        int l = left, r = right, m;

        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (target > arr[m]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return r;
    }
};

int main() {
    vector<int> arr = {0, 1, 3, 3, 4, 7, 7, 7, 9, 10};

    // 基础用例
    cout << "binarySearch(3): " << BinarySearch::binarySearch(arr, 3, 0, arr.size() - 1) << endl;   // 2 or 3
    cout << "binarySearch(11): " << BinarySearch::binarySearch(arr, 11, 0, arr.size() - 1) << endl; // -1

    // lowerBound
    cout << "lowerBound(7): " << BinarySearch::lowerBound(arr, 7, 0, arr.size() - 1) << endl;   // 5
    cout << "lowerBound(6): " << BinarySearch::lowerBound(arr, 6, 0, arr.size() - 1) << endl;   // 5
    cout << "lowerBound(0): " << BinarySearch::lowerBound(arr, 0, 0, arr.size() - 1) << endl;   // 0
    cout << "lowerBound(10): " << BinarySearch::lowerBound(arr, 10, 0, arr.size() - 1) << endl; // 9
    cout << "lowerBound(11): " << BinarySearch::lowerBound(arr, 11, 0, arr.size() - 1) << endl; // 10

    // upperBound
    cout << "upperBound(7): " << BinarySearch::upperBound(arr, 7, 0, arr.size() - 1) << endl;   // 8
    cout << "upperBound(6): " << BinarySearch::upperBound(arr, 6, 0, arr.size() - 1) << endl;   // 5
    cout << "upperBound(10): " << BinarySearch::upperBound(arr, 10, 0, arr.size() - 1) << endl; // 10

    // lastLE
    cout << "lastLE(7): " << BinarySearch::lastLE(arr, 7, 0, arr.size() - 1) << endl;   // 7
    cout << "lastLE(6): " << BinarySearch::lastLE(arr, 6, 0, arr.size() - 1) << endl;   // 4
    cout << "lastLE(10): " << BinarySearch::lastLE(arr, 10, 0, arr.size() - 1) << endl; // 9
    cout << "lastLE(-1): " << BinarySearch::lastLE(arr, -1, 0, arr.size() - 1) << endl; // -1

    // lastLT
    cout << "lastLT(7): " << BinarySearch::lastLT(arr, 7, 0, arr.size() - 1) << endl; // 4
    cout << "lastLT(0): " << BinarySearch::lastLT(arr, 0, 0, arr.size() - 1) << endl; // -1
    cout << "lastLT(8): " << BinarySearch::lastLT(arr, 8, 0, arr.size() - 1) << endl; // 7

    // 所有元素相等
    vector<int> all7(10, 7);
    cout << "all7 - lowerBound(7): " << BinarySearch::lowerBound(all7, 7, 0, all7.size() - 1) << endl; // 0
    cout << "all7 - upperBound(7): " << BinarySearch::upperBound(all7, 7, 0, all7.size() - 1) << endl; // 10
    cout << "all7 - lastLE(7): " << BinarySearch::lastLE(all7, 7, 0, all7.size() - 1) << endl;         // 9

    // 空数组
    vector<int> empty;
    cout << "empty - lowerBound(1): " << BinarySearch::lowerBound(empty, 1, 0, -1) << endl;     // 0
    cout << "empty - binarySearch(1): " << BinarySearch::binarySearch(empty, 1, 0, -1) << endl; // -1
}
