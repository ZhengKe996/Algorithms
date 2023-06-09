#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = 0; // 初始长度为0
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[n] = nums[i]; // 如果nums[i]==[i-1]则证明有重复元素
                n++;
            }
        }
        return n;
    }
};

int main() {

    Solution s;
    vector<int> list{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    auto ans = s.removeDuplicates(list);
    cout << ans;

}
