#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int ans = n;

        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (target <= nums[mid]) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> list = {1, 3, 5, 6};

    cout << s.searchInsert(list, 2);


    return 0;
}
