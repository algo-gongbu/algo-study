#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<pair<string, string>> rule;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text;
    cin >> text >> n;
    string temp;
    int pos, j;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        pos = temp.find('=');
        rule.push_back({temp.substr(0, pos), temp.substr(pos + 1)});
    }

    // for (int i = 0; i < n; i++) {
    //     cout << rule[i].first << ' ' << rule[i].second << '\n';
    // }

    int cnt = 0;
    while (true) {
        if (text.size() > 255) {
            cout << "Memory Limit Exceeded\n";
            return 0;
        }

        for (j = 0; j < n; j++) {
            if ((pos = text.find(rule[j].first)) != string::npos) {
                text.replace(pos, rule[j].first.size(), rule[j].second);
                // cout << text << '\n';
                break;
            }
        }

        if (j == n) {flag = true; break;}

        if (++cnt > 5000) break;
    }

    if (flag) cout << text << '\n';
    else cout << "Time Limit Exceeded\n";

    return 0;
}