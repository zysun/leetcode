#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * LeetCode 2841 - 几乎唯一子数组的最大和
 * 
 * 思路：滑动窗口 + 哈希表
 * 1. 窗口大小为 k，维护窗口内元素和 sum 以及各元素出现次数
 * 2. 当窗口内不同元素数 >= m 时，更新最大和
 * 3. 滑动时右加左减，同时维护哈希表
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(k)
 */
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long sum = 0, ans = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < (int)nums.size(); i++) {
            // 加入右边新元素
            sum += nums[i];
            freq[nums[i]]++;

            // 窗口已满
            if (i >= k - 1) {
                // 不同元素数 >= m，更新答案
                if ((int)freq.size() >= m) {
                    ans = max(ans, sum);
                }
                // 移除左边元素
                int leftVal = nums[i - k + 1];
                sum -= leftVal;
                if (--freq[leftVal] == 0) {
                    freq.erase(leftVal);
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    vector<int> nums1 = {2, 6, 7, 3, 1, 7};
    cout << "输入: nums = [2,6,7,3,1,7], m = 3, k = 4" << endl;
    cout << "输出: " << sol.maxSum(nums1, 3, 4) << endl;
    // 期望输出: 18 (子数组 [6,7,3,1] 或 [7,3,1,7])
    
    // 测试用例 2
    vector<int> nums2 = {5, 9, 9, 2, 4, 5, 4};
    cout << "输入: nums = [5,9,9,2,4,5,4], m = 1, k = 3" << endl;
    cout << "输出: " << sol.maxSum(nums2, 1, 3) << endl;
    // 期望输出: 23 (子数组 [9,9,5])
    
    // 测试用例 3
    vector<int> nums3 = {1, 2, 1, 2, 1, 2, 1};
    cout << "输入: nums = [1,2,1,2,1,2,1], m = 3, k = 3" << endl;
    cout << "输出: " << sol.maxSum(nums3, 3, 3) << endl;
    // 期望输出: 0 (没有子数组包含3个不同元素)
    
    return 0;
}