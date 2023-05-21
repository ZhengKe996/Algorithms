#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 快慢指针法
     * 有环必定发生套圈（快慢指针相遇），无环不会发生套圈（快指针到null）
     * @param head
     * @return
     */
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next; // 快指针每次走2步
            head = head->next;// 慢指针每次走一步
            if (fast == head) { // 如果有环（套圈）返回true
                return true;
            }
        }
        return false;
    }
};

int main() {
    return 0;
}
