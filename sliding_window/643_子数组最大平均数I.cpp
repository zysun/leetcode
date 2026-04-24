#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * LeetCode 643 - 子数组最大平均数 I
 * 
 * 思路：滑动窗口（定长）
 * 1. 先计算前 k 个元素的和作为初始窗口
 * 2. 窗口每次右移一位：加上右边新元素，减去左边旧元素
 * 3. 维护过程中记录最大和，最后除以 k 得到最大平均数
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // 初始化第一个窗口 [0, k) 的和
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        
        double maxSum = sum;
        
        // 滑动窗口：每次右移一位
        for (int i = k; i < (int)nums.size(); i++) {
            sum += nums[i] - nums[i - k];  // 右加左减
            maxSum = max(maxSum, sum);
        }
        
        return maxSum / k;
    }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    cout << "输入: nums = [1,12,-5,-6,50,3], k = " << k1 << endl;
    cout << "输出: " << sol.findMaxAverage(nums1, k1) << endl;
    // 期望输出: 12.75000 (子数组 [12,-5,-6,50] 的平均数)
    
    // 测试用例 2
    vector<int> nums2 = {5};
    int k2 = 1;
    cout << "输入: nums = [5], k = " << k2 << endl;
    cout << "输出: " << sol.findMaxAverage(nums2, k2) << endl;
    // 期望输出: 5.00000
    
    // 测试用例 3
    vector<int> nums3 = {0, 1, 2, 3, 4};
    int k3 = 2;
    cout << "输入: nums = [0,1,2,3,4], k = " << k3 << endl;
    cout << "输出: " << sol.findMaxAverage(nums3, k3) << endl;
    // 期望输出: 3.50000 (子数组 [3,4] 的平均数)
    
    // 测试用例 4
    vector<int> nums4 = {-1, -2, -3, -4, -5};
    int k4 = 2;
    cout << "输入: nums = [-1,-2,-3,-4,-5], k = " << k4 << endl;
    cout << "输出: " << sol.findMaxAverage(nums4, k4) << endl;
    // 期望输出: -1.50000 (子数组 [-1,-2] 的平均数)
    
    return 0;
}