#include <bits/stdc++.h>
using namespace std;

using namespace std;

int L, C;
vector<char> chars;
vector<string> ans;

bool isValid(string s) {
    int vowelsCount = 0;
    int consonantsCount = 0;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowelsCount++;
        } else {
            consonantsCount++;
        }
    }
    return vowelsCount >= 1 && consonantsCount >= 2;
}

void solve(int idx, string word) {
    if (word.size() == L) {
        if (isValid(word)) {
            ans.push_back(word);
        }
        return;
    }

    for (int i = idx; i < C; i++) {
        word.push_back(chars[i]);
        solve(i + 1, word);
        word.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> L >> C)) return 0;

    chars.resize(C);
    for (int i = 0; i < C; i++) {
        cin >> chars[i];
    }
    
    sort(chars.begin(), chars.end());

    solve(0, "");

    for (const string& s : ans) {
        cout << s << "\n";
    }

    return 0;
}