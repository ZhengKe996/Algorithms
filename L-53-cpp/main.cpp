#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> s(n + 1); // 0~n
        vector<int> preMin(n + 1); // 0~n
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }

        preMin[0] = s[0];
        for (int i = 1; i <= n; i++) {
            preMin[i] = min(preMin[i - 1], s[i]);
        }

        int ans = -1e6;
        for (int i = 1; i <= n; i++) {
            // 在i之前(0~i~1中找一个j)使得s[i]-s[j]最大
            ans = max(ans, s[i] - preMin[i - 1]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> list{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << s.maxSubArray(list);
    return 0;
}
