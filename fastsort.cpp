// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码不保证正确性，仅供参考。如有疑惑，可以参照我写的 java 代码对比查看。

#include <cstdlib>
#include <ctime>
#include<vector>
#include <iostream>

using namespace std;

// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码不保证正确性，仅供参考。如有疑惑，可以参照我写的 java 代码对比查看。

class Quick {
public:
    // 使用 static 关键字可以确保无需实例化 Quick 类即可进行排序
    static void sort(vector<int> &nums) {
        // 为了避免出现耗时的极端情况，先随机打乱
        // 排序整个数组（原地修改）
        sort(nums, 0, nums.size() - 1);
    }

private:
    static void sort(vector<int> &nums, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        // 对 nums[lo..hi] 进行切分
        // 使得 nums[lo..p-1] <= nums[p] < nums[p+1..hi]
        int p = partition(nums, lo, hi);

        sort(nums, lo, p - 1);
        sort(nums, p + 1, hi);
    }

    // 对 nums[lo..hi] 进行切分
    static int partition(vector<int> &nums, int left, int right) {
        // 以 nums[left] 为基准数
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] >= nums[left])
                j--; // 从右向左找首个小于基准数的元素
            while (i < j && nums[i] <= nums[left])
                i++;          // 从左向右找首个大于基准数的元素
            swap(nums[i], nums[j]); // 将基准数交换至两子数组的分界线

        }
        swap(nums[i], nums[left]); // 将基准数交换至两子数组的分界线
        return i;            // 返回基准数的索引
    }

    // 洗牌算法，将输入的数组随机打乱


    // 原地交换数组中的两个元素
    static void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main2() {

    vector<int> nums{5, 4, 3, 2, 1, 6};
    Quick::sort(nums);
    for (auto &i: nums) {
        cout << i << " ";
    }
    cout << endl;
}
