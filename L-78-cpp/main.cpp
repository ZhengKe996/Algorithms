#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        n = nums.size();
        recur(nums, 0);
        return ans;
    }

private:
    void recur(vector<int> &nums, int i) {
        // 递归边界
        if (i == n) {
            ans.push_back(chosen);
            return;
        }

        // 每层的相似逻辑，nums[i] 选或不选
        recur(nums, i + 1);
        chosen.push_back(nums[i]);
        recur(nums, i + 1);

        // 还原现成
        chosen.pop_back();
    }

    int n;
    vector<int> chosen;
    vector<vector<int>> ans;
};

int main() {
    Solution s;
    vector<int> nums{1, 2, 3};
    s.subsets(nums);
    return 0;
}
