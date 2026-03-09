#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int step[N + 1], dp[N + 1][5][5], idx;

int cost(int from, int to) {
    if (from == to) return 1;
    else if (from == 0) return 2;
    else if (abs(from - to) == 2) return 4;
    else return 3;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> n;
        if (n == 0) break;
        step[++idx] = n;
    }

    for (int i = 0; i <= idx; i++) {
        for (int l = 0; l < 5; l++) {
            for (int r = 0; r < 5; r++) {
                dp[i][l][r] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
    int next_step;
    for (int i = 0; i < idx; i++) {
        next_step = step[i + 1];

        for (int l = 0; l < 5; l++) {
            for (int r = 0; r < 5; r++) {
                if (dp[i][l][r] == INF) continue;

                dp[i + 1][next_step][r] = min(dp[i + 1][next_step][r], dp[i][l][r] + cost(l, next_step));
                dp[i + 1][l][next_step] = min(dp[i + 1][l][next_step], dp[i][l][r] + cost(r, next_step));
            }
        }
    }    

    minimum = dp[idx][0][0];
    for (int l = 0; l < 5; l++) {
        for (int r = 0; r < 5; r++) {
            minimum = min(minimum, dp[idx][l][r]);
        }
    }

    cout << minimum << '\n';

    return 0;
}