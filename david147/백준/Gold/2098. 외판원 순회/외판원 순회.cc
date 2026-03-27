#include <bits/stdc++.h>

using namespace std;

#define ll long long

int dp[16][1 << 16], cost[16][16], n;
const int INF = 1 << 28;

int dfs(int cur, int visited) {
    if (visited == ((1 << n) - 1)) {
        if (cost[cur][0]) return cost[cur][0];
        else return INF;                        // INF: no way back
    }

    if (dp[cur][visited] != -1) return dp[cur][visited];

    dp[cur][visited] = INF;
    for (int nxt = 0; nxt < n; ++nxt) {
        if ((visited & (1 << nxt)) || !cost[cur][nxt]) continue;

        dp[cur][visited] = min(dp[cur][visited], cost[cur][nxt] + dfs(nxt, visited | (1 << nxt)));
    }
    return dp[cur][visited];            
    // dp[cur][visited]: minimum cost to visit all remaining cities and return to starting point(in this code, 0)
    // cur: city in which currently we are
    // visited: cities which we visited so far
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            dp[i][j] = -1;                      // -1: not calculated
        }
    }

    cout << dfs(0, 1) << '\n';                  
    // no matter that we arbitrarily set the starting point to 0
    // due to the path we want to find is cyclic

    return 0;
}