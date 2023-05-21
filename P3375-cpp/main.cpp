#include<iostream>
#include<string>

using namespace std;
int slen;
int tlen;
int next2[1000000 + 5];

void get_next2(string t) {
    int j = 0, k = -1;
    next2[0] = -1;
    while (j < tlen)
        if (k == -1 || t[j] == t[k])
            next2[++j] = ++k;
        else
            k = next2[k];
}

void KMP(string s, string t) {
    int i = 0, j = 0;
    slen = s.length();
    tlen = t.length();
    get_next2(t);
    while (i < slen) {
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
        } else
            j = next2[j];
        if (j == tlen) {
            cout << i - tlen + 1 << endl;
            j = next2[j];
        }
    }
}

int main() {
    string s, t;
    cin >> s >> t;
    KMP(s, t);
    for (int i = 1; i <= tlen; i++) {
        cout << next2[i] << " ";
    }
    return 0;
}