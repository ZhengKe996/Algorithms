#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 将子段的奇数数量 -> 将数 mod 2，奇数为1，偶数为0；统计子段和是k的子段数量
     * [1,1,2,1,1,]->[1,1,2,1,1]->[1,1,0,1][1,0,1,1] k=3;
     * [2,4,6]->[0,0,0] k=0;
     * [2,2,2,1,2,2,1,2,2,2]->[0,0,0,1,0,0,1,0,0,0]
     * ->[0,0,0,1,0,0,1][0,0,1,0,0,1,0][0,1,0,0,1,0,0][1,0,0,1,0,0,0]
     *
     * @param nums
     * @param k 数组中有几个奇数
     * @return
     */
    int numberOfSubarrays(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        s[0] = 0;
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1] % 2;
        }

        vector<int> count(n + 1);
        int ans = 0;
        count[s[0]]++;

        for (int i = 1; i <= n; i++) {
            if (s[i] - k >= 0) {
                cout << "count " << count[s[i] - k] << "i " << i << endl;
                ans += count[s[i] - k];
            }
            count[s[i]]++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> list{2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;
    cout << s.numberOfSubarrays(list, k);
    return 0;
}
