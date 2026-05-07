#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int dp[31][31];
    for (int i=0; i<30; i++) {
        for (int j=0; j<=i; j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    
    int T; cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << dp[M][N] << "\n";
    }

    return 0;
}