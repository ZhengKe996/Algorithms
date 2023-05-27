#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        recur(1);
        return ans;
    }


private:
    void recur(int i) {
        // 剪枝：如果已经选了超过k个，或者说剩下的全部也不够k个说明一定不合法了，提前退出
        if (chosen.size() > k || chosen.size() + (n - i + 1) < k) {
            return;
        }
        // 递归边界
        if (i == n + 1) {
            if (chosen.size() == k) {
                ans.push_back(chosen);
            }
            return;
        }

        // 每层的相似逻辑，i 选或不选
        recur(i + 1);
        chosen.push_back(i);
        recur(i + 1);

        // 还原现成
        chosen.pop_back();
    }

    int n, k;
    vector<int> chosen;
    vector<vector<int>> ans;
};

int main() {
    Solution s;

    return 0;
}
