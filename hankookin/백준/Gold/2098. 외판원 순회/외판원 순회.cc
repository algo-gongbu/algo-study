#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int N, W[16][16], dp[16][1<<16];

int tsp(int curr, int mask) {
    if (mask == (1<<N)-1) {
        if (W[curr][0] != 0) {
            return W[curr][0];
        }
        return INF;
    } 

    if (dp[curr][mask] != -1) {
        return dp[curr][mask];
    }

    int min_cost = INF;
    for (int next=0; next<N; next++) {
        if (!(mask & (1<<next)) && W[curr][next] != 0) {
            int cost = W[curr][next] + tsp(next, mask | (1 << next));
            min_cost = min(min_cost, cost);
        }
    }

    return dp[curr][mask] = min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> W[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    int ans = tsp(0, 1);
    cout << ans << "\n";

    return 0;
}

