#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    /**
     * 暴力
     * @param nums
     * @param target
     * @return
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    /**
     * 哈希表
     * @param nums
     * @param target
     * @return
     */
    vector<int> twoSum2(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(target - nums[i]) != h.end()) {
                return {h[target - nums[i]], i};
            }
            h[nums[i]] = i;
        }
        return {};
    }

private:
    unordered_map<int, int> h;
};

int main() {
    Solution s;
    vector<int> nums{2, 7, 11, 15};
    vector<int> res1 = s.twoSum2(nums, 9);
    for (int i = 0; i < res1.size(); i++) {
        cout << res1[i] << endl;
    }

    return 0;
}
