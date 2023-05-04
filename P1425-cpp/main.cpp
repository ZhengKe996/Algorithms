#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d;
    x = ((c * 60 + d) - (a * 60 + b));
    e = x / 60;
    f = x % 60;
    cout << e << " " << f; // 注意输出格式
    return 0;
}
