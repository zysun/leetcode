#include <iostream>
#include <vector>
using namespace std;

/**
 * LeetCode 2090 - 半径为 k 的子数组平均值
 * 
 * 思路：滑动窗口（定长），单循环实现
 * 1. 窗口大小为 2*k+1，以每个位置 i 为中心，取左右各 k 个元素
 * 2. ans 初始化为全 -1，只有窗口满时才更新对应中心位置
 *    - 前 k 个位置和后 k 个位置永远不会被更新，自然保持 -1
 * 3. 单循环中同时完成：累加元素、窗口满时计算平均值、右移时右加左减
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)（不计返回数组）
 */
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        int windowSize = 2 * k + 1;
        vector<int> ans(n, -1);  // 默认全为 -1，前后不足 k 个元素的位置自然保持 -1
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            // 加入右边新元素
            sum += nums[i];

            // 窗口已满（i >= 2k），计算中心位置的平均值
            if (i >= windowSize - 1) {
                int center = i - k;  // 当前窗口的中心下标
                ans[center] = sum / windowSize;
                // 移除左边即将滑出的元素（为下一轮右移做准备）
                sum -= nums[center - k];
            }
        }

        return ans;
    }
};

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i < (int)v.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    
    // 测试用例 1
    vector<int> nums1 = {7, 4, 3, 9, 1, 8, 5, 2, 6};
    int k1 = 3;
    cout << "输入: nums = [7,4,3,9,1,8,5,2,6], k = " << k1 << endl;
    cout << "输出: ";
    printVector(sol.getAverages(nums1, k1));
    // 期望输出: [-1,-1,-1,5,4,4,-1,-1,-1]
    
    // 测试用例 2
    vector<int> nums2 = {100000};
    int k2 = 0;
    cout << "输入: nums = [100000], k = " << k2 << endl;
    cout << "输出: ";
    printVector(sol.getAverages(nums2, k2));
    // 期望输出: [100000]
    
    // 测试用例 3
    vector<int> nums3 = {8};
    int k3 = 100000;
    cout << "输入: nums = [8], k = " << k3 << endl;
    cout << "输出: ";
    printVector(sol.getAverages(nums3, k3));
    // 期望输出: [-1]
    
    // 测试用例 4
    vector<int> nums4 = {1, 2, 3, 4, 5};
    int k4 = 1;
    cout << "输入: nums = [1,2,3,4,5], k = " << k4 << endl;
    cout << "输出: ";
    printVector(sol.getAverages(nums4, k4));
    // 期望输出: [-1,2,3,4,-1]
    
    return 0;
}