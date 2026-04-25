#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * LeetCode 3679 - 平衡库存的最少丢弃数
 * 
 * 思路：滑动窗口（定长）
 * 1. 维护一个大小为 w 的滑动窗口，记录窗口内每种类型的保留数量
 * 2. 当窗口滑出时，如果滑出的物品是被保留的，则减少其频率
 * 3. 当新物品到达时，如果其类型在窗口内已达到 m 次，则丢弃；否则保留
 * 4. 用 kept[] 数组记录每个位置是否被保留，用于窗口滑出时判断是否需要减少频率
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n + k)，k 为不同物品类型的数量
 */
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        unordered_map<int, int> freq;   // 当前窗口内每种类型的保留数量
        vector<bool> kept(n, false);    // 记录每个位置的物品是否被保留
        int discards = 0;

        for (int i = 0; i < n; i++) {
            // 1. 窗口滑出：移除超出窗口范围的物品
            if (i >= w && kept[i - w]) {
                freq[arrivals[i - w]]--;
            }

            // 2. 判断当前物品是否可以保留
            if (freq[arrivals[i]] < m) {
                freq[arrivals[i]]++;
                kept[i] = true;
            } else {
                discards++;
            }
        }

        return discards;
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> arrivals1 = {1, 2, 1, 3, 1};
    int w1 = 4, m1 = 2;
    cout << "输入: arrivals = [1,2,1,3,1], w = " << w1 << ", m = " << m1 << endl;
    cout << "输出: " << sol.minArrivalsToDiscard(arrivals1, w1, m1) << endl;
    // 期望输出: 0

    // 测试用例 2
    vector<int> arrivals2 = {1, 2, 3, 3, 3, 4};
    int w2 = 3, m2 = 2;
    cout << "输入: arrivals = [1,2,3,3,3,4], w = " << w2 << ", m = " << m2 << endl;
    cout << "输出: " << sol.minArrivalsToDiscard(arrivals2, w2, m2) << endl;
    // 期望输出: 1

    // 测试用例 3：所有物品都相同，窗口大小为 1，m = 1
    vector<int> arrivals3 = {1, 1, 1, 1};
    int w3 = 1, m3 = 1;
    cout << "输入: arrivals = [1,1,1,1], w = " << w3 << ", m = " << m3 << endl;
    cout << "输出: " << sol.minArrivalsToDiscard(arrivals3, w3, m3) << endl;
    // 期望输出: 0（每个窗口只有 1 个元素）

    // 测试用例 4：所有物品都相同，窗口大小为 3，m = 1
    vector<int> arrivals4 = {1, 1, 1, 1};
    int w4 = 3, m4 = 1;
    cout << "输入: arrivals = [1,1,1,1], w = " << w4 << ", m = " << m4 << endl;
    cout << "输出: " << sol.minArrivalsToDiscard(arrivals4, w4, m4) << endl;
    // 期望输出: 2（第 2、3 个 1 需要丢弃）

    return 0;
}