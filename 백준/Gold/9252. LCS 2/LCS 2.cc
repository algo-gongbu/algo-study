#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
string s1, s2;
int dp[N + 1][N + 1];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    string text = "";
    
    int i = s1.size(), j = s2.size();
    while (i > 0 && j > 0) {
        if (dp[i][j] > max(dp[i - 1][j], dp[i][j - 1])) {text = s1[i - 1] + text; --i; --j;}
        else {
            if (dp[i][j] == dp[i - 1][j]) --i;
            else if (dp[i][j] == dp[i][j - 1]) --j;
        }
    }

    cout << dp[s1.size()][s2.size()] << '\n' << text << '\n';

    return 0;
}