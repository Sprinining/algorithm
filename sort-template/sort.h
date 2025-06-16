#include <vector>
namespace my_sort {
class Sort {
  public:
    void bubbleSort(std::vector<int>& arr);

  private:
    // 用指针的方式交换两个数
    void swapByPtr(int* a, int* b);

    // 用引用交换
    void swapByRef(int& a, int& b);

    // 使用 XOR 实现的交换
    void xorSwap(int* a, int* b);
};
}