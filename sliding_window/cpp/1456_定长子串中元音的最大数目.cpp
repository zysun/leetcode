#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/**
 * LeetCode 1456 - 定长子串中元音的最大数目
 * 
 * 思路：滑动窗口
 * 1. 先计算前 k 个字符中的元音数量
 * 2. 然后窗口每次右移一位：右边新加入一个字符，左边移出一个字符
 * 3. 维护窗口内元音数量，记录最大值
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        // 初始化第一个窗口 [0, k)
        int count = 0;
        for (int i = 0; i < k && i < (int)s.size(); i++) {
            if (vowels.count(s[i])) {
                count++;
            }
        }
        
        int maxCount = count;
        
        // 滑动窗口：每次右移一位
        for (int i = k; i < (int)s.size(); i++) {
            // 右边加入 s[i]
            if (vowels.count(s[i])) {
                count++;
            }
            // 左边移出 s[i - k]
            if (vowels.count(s[i - k])) {
                count--;
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    string s1 = "abciiidef";
    int k1 = 3;
    cout << "输入: s = \"" << s1 << "\", k = " << k1 << endl;
    cout << "输出: " << sol.maxVowels(s1, k1) << endl;
    // 期望输出: 3 ("iii")
    
    // 测试用例 2
    string s2 = "aeiou";
    int k2 = 2;
    cout << "输入: s = \"" << s2 << "\", k = " << k2 << endl;
    cout << "输出: " << sol.maxVowels(s2, k2) << endl;
    // 期望输出: 2 ("ae")
    
    // 测试用例 3
    string s3 = "leetcode";
    int k3 = 3;
    cout << "输入: s = \"" << s3 << "\", k = " << k3 << endl;
    cout << "输出: " << sol.maxVowels(s3, k3) << endl;
    // 期望输出: 2 ("eet" 或 "eod")
    
    // 测试用例 4
    string s4 = "rhythms";
    int k4 = 4;
    cout << "输入: s = \"" << s4 << "\", k = " << k4 << endl;
    cout << "输出: " << sol.maxVowels(s4, k4) << endl;
    // 期望输出: 0
    
    // 测试用例 5
    string s5 = "tryhard";
    int k5 = 4;
    cout << "输入: s = \"" << s5 << "\", k = " << k5 << endl;
    cout << "输出: " << sol.maxVowels(s5, k5) << endl;
    // 期望输出: 1
    
    return 0;
}