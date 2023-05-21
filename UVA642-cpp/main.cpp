#include <iostream>
#include <map>

using namespace std;

struct node {
    string word[100 + 5];
    int cnt;
};
map<string, node> dict;

int main() {
    string s, temp;
    while (cin >> s && s != "XXXXXX") {
        temp = s;
        sort(s.begin(), s.end());
        dict[s].word[dict[s].cnt++] = temp;
    }
    while (cin >> s && s != "XXXXXX") {
        sort(s.begin(), s.end());
        if (!dict[s].cnt) {
            cout << "NOT A VALID WORD" << endl << "******" << endl;
            continue;
        }
        sort(dict[s].word, dict[s].word + dict[s].cnt);
        for (int i = 0; i < dict[s].cnt; i++) {
            cout << dict[s].word[i] << endl;
        }
        cout << "******" << endl;
    }
    return 0;
}
