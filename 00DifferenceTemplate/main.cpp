#include <iostream>

using namespace std;

const int N = 100010;
int n, m;
int a[N], b[N];

/**
 * 插入
 * @param l
 * @param r
 * @param c
 */
void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

/**
 * 一维差分 给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1

输出：3 4 5 3 4 2

 */
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i <= n; i++) {
        insert(i, i, a[i]);
    }

    while (m--) {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }


    for (int i = 1; i <= n; i++) {
        b[i] += b[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", b[i]);
    }

    return 0;
}
