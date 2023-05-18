#include <iostream>
#include <queue>

using namespace std;

/**
 * 注：题意 只要队列中有优先级更高的 就不能打印放回队尾
 * @return
 */
int main() {
    int T, n, m;
    cin >> T;
    for (int i = 0; i < T; i++) {
        queue<int> q;
        vector<int> a, b; // a存储优先级 b优先级排序
        int k = 0, x;
        cin >> n >> m; // m是打印作业编号 从0开始
        for (int j = 0; j < n; j++) {
            cin >> x;
            a.push_back(x);
            b.push_back(x);
            q.push(j); // q队列存储的下标 从0开始
        }
        sort(b.begin(), b.end(), greater<int>()); // 对b进行排序 降序（默认是升序）
        int w = 0; // 指向队列中优先级最高的下标
        int max = 0; // 读取队列中最大优先级
        while (!q.empty()) {
            max = b[w];
            int t = q.front(); // 取队头
            if (a[t] < max) { //  只要队列中有优先级更高的 就不能打印，放回队尾
                q.pop();
                q.push(t);
            } else {
                if (t == m) {
                    cout << ++k << endl; // k计数器记录 第几个数是最高
                    break;
                } else {
                    q.pop();
                    k++; // 计数器++
                    w++; // 优先级数组下标++
                }
            }
        }
    }
    return 0;
}
