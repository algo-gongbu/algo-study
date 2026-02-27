#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int C, N;
    cin >> C >> N;

    vector<pair<int,int>> ad(N);
    vector<int> dp(C+101, 1e9);
    dp[0] = 0;

    for (int i=0; i<N; i++) {
        int cost, guests;
        cin >> cost >> guests;
        ad[i] = {cost, guests};
    }

    for (int i=0; i<N; i++) {
        int cost = ad[i].first;
        int guests = ad[i].second;

        for (int j=guests; j<=C+100; j++) {
            if (dp[j-guests] != 1e9) {
                dp[j] = min(dp[j], dp[j-guests]+cost);
            }
        }
    }

    int min_cost = 1e9;
    for (int i=C; i<=C+100; i++) {
        min_cost = min(min_cost, dp[i]);
    }
    cout << min_cost << '\n';
    
    return 0;
}