#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (j >= n || (i < m && nums1[i] <= nums2[j])) { // 谁小要谁；j出界或i，j都没出界的情况下要小的
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }

        for (int k = 0; k < m + n; k++) {
            nums1[k] = result[k];
        }
    };

    /* 省空间 */
    void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1;
        for (int k = m + n - 1; k >= 0; k--) {
            // 谁大要谁；j出界或i，j都没出界的情况下要小的
            if (j < 0 || (i >= 0 && nums1[i] >= nums2[j])) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
        }
    }
};

int main() {
    Solution s;

    vector<int>
            nums1{1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    int m = 3, n = 3;

    s.merge2(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
    }
    return 0;
}
