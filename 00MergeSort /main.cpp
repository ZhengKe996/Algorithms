#include <iostream>

using namespace std;
const int N = 100010;
int n;
int q[N], tmp[N];


/**
 * 归并排序模版
 * @param q 需要排序的数组
 * @param l 左边界
 * @param r 右边界
 */
void merge_sort(int q[], int l, int r) {
    if (l >= r) return;

    int mid = l + r >> 1; // 取中值

    merge_sort(q, l, mid); // 递归排序
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;

    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) {
            tmp[k++] = q[i++];
        } else {
            tmp[k++] = q[j++];
        }
    }

    while (i <= mid) {
        tmp[k++] = q[i++];
    }

    while (j <= r) {
        tmp[k++] = q[j++];
    }

    for (i = l, j = 0; i <= r; i++, j++) {
        q[i] = tmp[j];
    }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    merge_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", q[i]);
    }

    return 0;
}
