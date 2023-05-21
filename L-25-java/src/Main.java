class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}


class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode protect = new ListNode(0, head);
        ListNode last = protect;
        // 分组遍历
        while (head != null) {
            // 1. 分组（往后走k-1步，找到一组）
            ListNode end = getEnd(head, k);
            if (end == null) {
                break;
            }

            ListNode nextGroupHead = end.next;

            // 2. 一组内部（head-end）要反转，调用反转链表
            reverseList(head, nextGroupHead);

            // 3. 更新每一组跟前一组、后一组之间的边；
            last.next = end;
            head.next = nextGroupHead;

            last = head;

            head = nextGroupHead;
        }

        return protect.next;
    }

    // 反转链表，在结点step
    private ListNode reverseList(ListNode head, ListNode stop) {
        ListNode last = head;
        head = head.next;
        while (head != stop) {
            ListNode nextHead = head.next;
            head.next = last;
            last = head;
            head = nextHead;
        }
        return last;
    }

    // 返回走k-1步之后的结点；返回null表示不够k个
    private ListNode getEnd(ListNode head, int k) {
        while (head != null) {
            k--;
            if (k == 0) {
                return head;
            }
            head = head.next;
        }
        return null;
    }
}

public class Main {
    public static void main(String[] args) {

    }
}