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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        this.preorder = preorder;
        this.inorder = inorder;
        return build(0, preorder.length - 1, 0, inorder.length - 1);
    }

    // 用 preorder[l1...r1] 和 inorder[l2...r2]还原二叉树
    TreeNode build(int l1, int r1, int l2, int r2) {
        if (l1 > r1) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[l1]);
        int mid = l2;// mid 是root在inorder中的位置;
        while (inorder[mid] != root.val) {
            mid++;
        }

        root.left = build(l1 + 1, l1 + (mid - l2), l2, mid - 1);
        root.right = build(l1 + (mid - l2) + 1, r1, mid + 1, r2);
        return root;
    }


    int[] preorder, inorder;
}

public class Main {
    public static void main(String[] args) {

    }
}