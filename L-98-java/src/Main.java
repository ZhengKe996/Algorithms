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
    public boolean isValidBST(TreeNode root) {
        return check(root, -(1l << 31), (1l << 31) - 1);
    }

    private boolean check(TreeNode root, long rangeLeft, long rangeRight) {
        if (root == null) return true;
        if (root.val < rangeLeft || root.val > rangeRight) {
            return false;
        }

        return check(root.left, rangeLeft, (long) root.val - 1) && check(root.right, (long) root.val + 1, rangeRight);
    }
}

public class Main {
    public static void main(String[] args) {

        Solution s = new Solution();

    }
}