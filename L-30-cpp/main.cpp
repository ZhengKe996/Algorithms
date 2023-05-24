#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * 判定方式：
     *      给出一个S的子串、words，判定这个子串是不是 words 的串联？
     *      把子串划分以后，其实就是比较两个 Hash map 是否相等?
     *
     * @param s
     * @param words
     * @return
     */
    vector<int> findSubstring(string s, vector<string> &words) {
        int tot = 0;
        for (string &word: words) {
            tot += word.length();
            wordsMap[word]++;
        }

        vector<int> ans;
        for (int i = 0; i + tot <= s.length(); i++) {
            if (valid(s.substr(i, tot), words)) {
                ans.push_back(i);
            }
        }
        return ans;
    }

private:
    bool valid(string str, vector<string> &words) {
        int k = words[0].length();
        unordered_map<string, int> splitWordsMap;
        for (int i = 0; i < str.length(); i += k) {
            splitWordsMap[str.substr(i, k)]++;
        }

        return equalsMap(splitWordsMap, wordsMap);
    }

    bool equalsMap(unordered_map<string, int> &a, unordered_map<string, int> &b) {
        for (auto &key_and_value: a) {
            const string &key = key_and_value.first;
            int value = key_and_value.second;
            if (b.find(key) == b.end() || b[key] != value) {
                return false;
            }
        }

        for (auto &key_and_value: b) {
            const string &key = key_and_value.first;
            int value = key_and_value.second;
            if (a.find(key) == a.end() || a[key] != value) {
                return false;
            }
        }
        return true;
    }

    unordered_map<string, int> wordsMap;
};

int main() {
    Solution s;

    string list = "barfoothefoobarman";
    vector<string> words{"foo", "bar"};
    auto res = s.findSubstring(list, words);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
