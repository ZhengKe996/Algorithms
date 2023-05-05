# 解题思路

本题没有唯一解，由题知 `y[i]=min(x[i],z[i])` z字符串为所求字符串；只要满足条件 `x[i]>=y[i]`的字符串即为正确解

```c++
int main() {
    int n;
    string x, y, res;
    cin >> n;
    cin >> x;
    cin >> y;

    for (int i = 0; i < n; i++) {
        if (x[i] < y[i]) {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << y;

    return 0;
}
```