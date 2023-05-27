#include <iostream>

using namespace std;

/**
 * 双指针解题
 */
class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            ans = max(ans, min(height[i], height[j]) * (j - i)); // j-i 为底 height[j] 高
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> list{1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << s.maxArea(list);
    return 0;
}
