#include <iostream>

using namespace std;

int main() {
    long x, n, count = 1;
    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        count = count + count * x;
    }
    cout << count;
    return 0;
}
