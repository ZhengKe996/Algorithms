#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 先排序再去重，找第k小的元素
 *
 * 1.去重函数会去除相邻连续的重复元素，不相邻的不会去除
 * 2.去重函数返回去重后的尾指针
 * 3.去重后数组的长度并未改变，如果有必要可以擦除
 */
int n, k, a[10005];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n); // 升序(降序 greater<int>())
    /**
     * unique(a,a+n)表示去重
     */
    int n2 = unique(a, a + n) - a; // 表示去重后的元素个数

    for (int i = 0; i < n2; i++) { // 这行代码AC时需注释
        cout << a[i] << " ";// 这行代码AC时需注释
    }
    cout << endl;// 这行代码AC时需注释

    if (k <= n2) {
        cout << a[k - 1];
    } else {
        cout << "NO RESULT";
    }

    return 0;
}
