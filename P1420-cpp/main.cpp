#include <iostream>

using namespace std;

int main() {
    int n, count = 1, max = 0; // count存的是连续个数；max存的是最大值，当count>max时，max=count
    int list[10000 + 5];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }

    for (int i = 0; i < n; i++) {
        if (list[i + 1] == list[i] + 1) {
            count++;
            if (max < count) {
                max = count;
            }
        } else {
            count = 1;
        }
    }
    cout << max<<endl;
    return 0;
}
