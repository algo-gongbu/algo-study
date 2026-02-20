#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int dp[21][21][21];

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            dp[0][i][j] = dp[i][0][j] = dp[i][j][0] = 1;
        }
    }
    
    for (int i = 1; i < 21; i++) {
        for (int j = 1; j < 21; j++) {
            for (int k = 1; k < 21; k++) {
                if (i < j && j < k) dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                else dp[i][j][k] = dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] - dp[i - 1][j - 1][k - 1];
            }
        }
    }
    
    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        
        if (a <= 0 || b <= 0 || c <= 0) ans = 1;
        else if (a > 20 || b > 20 || c > 20) ans = dp[20][20][20];
        else ans = dp[a][b][c];
        
        printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
    }

    return 0;
}