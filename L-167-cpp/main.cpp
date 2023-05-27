#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int j = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); i++) {
            while (i < j && numbers[i] + numbers[j] > target) {
                j--;
            }
            if (i < j && numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};

int main() {
    Solution s;

    vector<int> list{2, 7, 11, 15};
    auto res = s.twoSum(list, 9);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
