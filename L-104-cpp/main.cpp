#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /**
     * 思路二（自顶向下维护信息）
     * 把“深度〞作为一个全局变量——一个跟随结点移动而动态变化的信息
     * 递归一层，变量+1，在叶子处更新答案
     */
    int maxDepth(TreeNode *root) {
        ans = 0;
        depth = 1;
        calc(root);
        return ans;
    }

private:
    void calc(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        ans = max(ans, depth);
        depth++;
        calc(root->left);
        calc(root->right);
        depth--;
    }

    int depth;
    int ans;
};

int main() {
    return 0;
}
