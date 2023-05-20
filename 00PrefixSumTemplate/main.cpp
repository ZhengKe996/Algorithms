#include <iostream>

using namespace std;

/**
 * 前缀和:指某序列的前n项和，可以把它理解为数学上的数列的前n项和。
 * 计算公式：s[r]-s[l-1]
 *
 * S[i] = a[1] + a[2] + ... a[i]
 * a[l] + ... + a[r] = S[r] - S[l - 1]
 */

const int N = 100010;
int n, m;
int a[N], s[N];

int main() {
    ios::sync_with_stdio(false); // 原理：让cin和标准输入输出不同步，作用：提高cin的读取速度，副作用：不能再使用printf

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i <= n; i++) { // 前缀和的初始化
        s[i] = s[i - 1] + a[i];
    }
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]); // 区间和的计算
    }
    return 0;
}
