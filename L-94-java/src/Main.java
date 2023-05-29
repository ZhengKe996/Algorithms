import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        seq = new ArrayList<Integer>();
        dfs(root);
        return seq;
    }

    void dfs(TreeNode root) {
        if (root == null) {
            return;
        }

        dfs(root.left);
        seq.add(root.val);
        dfs(root.right);
    }

    List<Integer> seq;
}

public class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
    }
}