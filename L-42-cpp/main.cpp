#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int trap(vector<int> &heights) {
        int ans = 0;
        for (int height: heights) {
            int accumulatedWidth = 0; // 累加宽度
            while (!s.empty() && s.top().height <= height) {
                int bottom = s.top().height;
                accumulatedWidth += s.top().width;
                s.pop();

                if (s.empty()) {// 栈为空 则最左侧水要流走
                    continue;
                }
                // 以bottom为底的横块水最高可以到up（左右两侧的高度的min）
                int up = min(height, s.top().height);
                ans += accumulatedWidth * (up - bottom);
            }
            s.push({accumulatedWidth + 1, height});
        }
        return ans;
    }

private:
    struct Rect {
        int width;
        int height;
    };
    stack<Rect> s;
};

int main() {
    Solution s;
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(height);
    return 0;
}
