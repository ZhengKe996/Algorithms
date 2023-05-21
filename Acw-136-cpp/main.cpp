#include <iostream>
#include <algorithm>

using namespace std;

struct Node { // 双向链表
    int val;
    int idx;
    Node *pre;
    Node *next;
};

const int N = 100005;


int n;
int a[N], rk[N], ans[N];
Node *pos[N];


/**
 * 双链表插入模版，在node后插入新结点
 * @param node
 * @param idx
 * @return
 */
Node *AddNode(Node *node, int idx) {
    Node *newNode = new Node();
    newNode->val = a[idx];
    newNode->idx = idx;
    node->next->pre = newNode;
    newNode->next = node->next;
    newNode->pre = node;
    node->next = newNode;

    return newNode;
}

/**
 * 双链表删除模版
 * 前驱的后缀指向 后缀；后缀的前驱指向 前驱；互相指
 * @param node
 */
void DeleteNode(Node *node) {
    node->pre->next = node->next;
    node->next->pre = node->pre;
    delete node;
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        rk[i] = i;
    }
    // rk的含义：rank[i]表示排第i名的是哪个下标
    // 有序序列：a[rk[1]],a[rk[2]].....a[rk[n]]
    // a=[1,5,3,4,2] rk=[1,5,3,4,2] a[rk]=[1,2,3,4,5]

    // 排序
    sort(rk + 1, rk + n + 1, [&](int rki, int rkj) {
        return a[rki] < a[rkj];
    });

    // 保护结点
    Node head;
    Node tail;
    head.next = &tail;
    tail.pre = &head;
    head.val = a[rk[1]] - 1e9; // 比最小的数再小1e9
    tail.val = a[rk[n]] + 1e9;// 比最大的数再大1e9

    // 插入链表
    for (int i = 1; i <= n; i++) {
        // 数值：a[rk[i]],下标：rk[i]
        pos[rk[i]] = AddNode(tail.pre, rk[i]);
    }

    // 倒着考虑(前驱差值-后缀差值)
    for (int i = n; i > 1; i--) {
        Node *curr = pos[i];
        if (a[i] - curr->pre->val <= curr->next->val - a[i]) { // 谁小要谁
            ans[i] = curr->pre->idx; // 前驱小 放前驱
        } else {
            ans[i] = curr->next->idx;// 后缀小 放后缀
        }
        DeleteNode(curr);
    }

    for (int i = 2; i <= n; i++) {
        printf("%d %d\n", abs(a[ans[i]] - a[i]), ans[i]);
    }


    return 0;
}
