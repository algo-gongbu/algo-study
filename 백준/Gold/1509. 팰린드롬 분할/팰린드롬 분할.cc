#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string text;
    cin >> text;

    vector<vector<bool>> is_pal(text.size(), vector<bool>(text.size(), false));
    for (int i = 0; i < text.size(); ++i) is_pal[i][i] = true;
    for (int i = 0; i < text.size() - 1; ++i) {
        if (text[i] == text[i + 1]) is_pal[i][i + 1] = true;
    }
    for (int i = 2; i < text.size(); ++i) {
        for (int j = 0; j < text.size() - i; ++j) {
            if (text[j] == text[j + i]) is_pal[j][j + i] = is_pal[j + 1][j + i - 1];
        }
    }

    // for (int i = 0; i < text.size(); ++i) {
    //     for (int j = 0; j < text.size(); ++j) {
    //         cout << is_pal[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<int> dp(text.size() + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= text.size(); ++i) {
        for (int j = i; j >= 1; j--) {
            if (is_pal[j - 1][i - 1]) dp[i] = min(dp[i], dp[j - 1] + 1);
        }
    }

    cout << dp[text.size()] << '\n';

    return 0;
}