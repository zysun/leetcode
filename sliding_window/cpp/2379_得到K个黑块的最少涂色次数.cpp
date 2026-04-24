#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

/**
 * LeetCode 2379 - 得到 K 个黑块的最少涂色次数
 * 
 * 思路：滑动窗口（定长）
 * 1. 窗口大小为 k，统计窗口内白色块 'W' 的数量
 * 2. 白色块数量就是需要涂色的次数
 * 3. 滑动过程中记录最小值
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;  // 窗口内 'W' 的数量
        int ans = INT_MAX;

        for (int i = 0; i < (int)blocks.size(); i++) {
            // 加入右边新元素
            if (blocks[i] == 'W') count++;

            // 窗口已满（i >= k-1 时，已收集 k 个元素）
            if (i >= k - 1) {
                ans = min(ans, count);
                // 移除左边即将滑出的元素
                if (blocks[i - k + 1] == 'W') count--;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    string s1 = "WBBWWBBWBW";
    int k1 = 7;
    cout << "输入: blocks = \"" << s1 << "\", k = " << k1 << endl;
    cout << "输出: " << sol.minimumRecolors(s1, k1) << endl;
    // 期望输出: 3
    
    // 测试用例 2
    string s2 = "WBWBBBW";
    int k2 = 2;
    cout << "输入: blocks = \"" << s2 << "\", k = " << k2 << endl;
    cout << "输出: " << sol.minimumRecolors(s2, k2) << endl;
    // 期望输出: 0
    
    // 测试用例 3
    string s3 = "BWWWBB";
    int k3 = 6;
    cout << "输入: blocks = \"" << s3 << "\", k = " << k3 << endl;
    cout << "输出: " << sol.minimumRecolors(s3, k3) << endl;
    // 期望输出: 3
    
    return 0;
}