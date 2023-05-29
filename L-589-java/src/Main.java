import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class Node {
    public int val;
    public List<Node> children;

    public Node() {
    }

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    /**
     * 递归法
     *
     * @param root
     * @return
     */
    public List<Integer> preorder(Node root) {
        seq = new ArrayList<Integer>();
        dfs(root);
        return seq;
    }

    void dfs(Node root) {
        if (root == null) {
            return;
        }
        seq.add(root.val);
        for (Node child : root.children) {
            dfs(child);
        }
    }

    List<Integer> seq;


    /**
     * 迭代法
     *
     * @param root
     * @return
     */
    public List<Integer> preorder2(Node root) {
        seq = new ArrayList<Integer>();
        if (root == null) {
            return seq;
        }
        Stack<Node> stack = new Stack<Node>();
        stack.push(root);
        while (!stack.empty()) {
            Node node = stack.pop();
            seq.add(node.val);
            for (int i = node.children.size() - 1; i >= 0; i--) {
                stack.push(node.children.get(i));
            }
        }
        return seq;
    }
}

public class Main {
    public static void main(String[] args) {

    }
}