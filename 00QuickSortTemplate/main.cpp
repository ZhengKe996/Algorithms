#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int q[N];

/**
 * 快速排序模版
 * @param q
 * @param l
 * @param r
 */
void quick_sort(int q[], int l, int r) {
    if (l >= r) {
        return;
    }

    int x = q[l], i = l - 1, j = r + 1;// i左边界 j右边界 x 分界点
    while (i < j) { // i是从左往右 j从右往左
        do {
            i++;
        } while (q[i] < x); // 小于分界点则++

        do {
            j--;
        } while (q[j] > x);// 大于分界点则++

        if (i < j) { // 若 q[i]>q[j] 则交换位置
            swap(q[i], q[j]);
            /*
             * 若语言中没有swap 则可以手写
                int tmp = q[i];
                q[i] = q[j];
                q[j] = tmp;
             */
        }
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}


int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }
    quick_sort(q, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d", q[i]);
    }
    return 0;
}
