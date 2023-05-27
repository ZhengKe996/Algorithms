#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        n = nums.size();
        used = vector<bool>(n, false);
        recur(nums, 0);
        return ans;
    }

private:
    void recur(vector<int> &nums, int pos) {
        if (pos == n) {
            ans.push_back(a);
            return;
        }


        for (int i = 0; i < n; i++) {

            if (i > 0 && nums[i] == nums[i - 1] && !used[i]) {
                continue;
            }

            if (!used[i]) {
                a.push_back(nums[i]);
                used[i] = true;
                recur(nums, pos + 1);
                used[i] = false;
                a.pop_back();
            }
        }

    }

    vector<bool> used;
    vector<int> a;
    int n;
    vector<vector<int>> ans;

};

int main() {
    return 0;
}
