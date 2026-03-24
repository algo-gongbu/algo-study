#include <bits/stdc++.h>
using namespace std;

int get_min_len(int L, const string& s) {
    vector<int> pi(L, 0);
    int j = 0;

    for (int i=1; i<L; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if (s[i] == s[j]) pi[i] = ++j;
    }
    return L - pi[L-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L; string s;
    cin >> L >> s;

    cout << get_min_len(L, s) << "\n";

    return 0;
}