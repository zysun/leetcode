#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * LeetCode 1423 - 可获得的最大点数
 * 
 * 思路：反向思维 + 滑动窗口
 * 1. 从两端取 k 张牌，等价于：保留中间 n-k 张连续的牌
 * 2. 要使取出的点数最大，就要使保留的点数最小
 * 3. 用滑动窗口找长度为 n-k 的连续子数组的最小和
 * 4. 答案 = 总和 - 最小和
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int m = n - k;  // 需要保留的连续子数组长度
        
        // 边界：k == n 时取所有牌，直接返回总和
        if (m == 0) {
            int total = 0;
            for (int x : cardPoints) total += x;
            return total;
        }
        
        int sum = 0;       // 当前窗口和
        int total = 0;     // 总和
        int minSum = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            sum += cardPoints[i];
            total += cardPoints[i];
            
            if (i >= m - 1) {  // 窗口已满
                minSum = min(minSum, sum);
                sum -= cardPoints[i - m + 1];  // 移除左边元素
            }
        }
        
        return total - minSum;
    }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 1};
    cout << "输入: cardPoints = [1,2,3,4,5,6,1], k = 3" << endl;
    cout << "输出: " << sol.maxScore(nums1, 3) << endl;
    // 期望输出: 12 (取 [1,6,1] 或 [1,6,1])
    
    // 测试用例 2
    vector<int> nums2 = {2, 2, 2};
    cout << "输入: cardPoints = [2,2,2], k = 2" << endl;
    cout << "输出: " << sol.maxScore(nums2, 2) << endl;
    // 期望输出: 4
    
    // 测试用例 3
    vector<int> nums3 = {9, 7, 7, 9, 7, 7, 9};
    cout << "输入: cardPoints = [9,7,7,9,7,7,9], k = 7" << endl;
    cout << "输出: " << sol.maxScore(nums3, 7) << endl;
    // 期望输出: 55 (取所有牌)
    
    // 测试用例 4
    vector<int> nums4 = {1, 1000, 1};
    cout << "输入: cardPoints = [1,1000,1], k = 1" << endl;
    cout << "输出: " << sol.maxScore(nums4, 1) << endl;
    // 期望输出: 1 (取左边1或右边1)
    
    return 0;
}