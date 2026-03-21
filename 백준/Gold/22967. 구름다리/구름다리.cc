#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 300
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
bool adj[N + 1][N + 1];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int start, end;
    for (int i = 0; i < n - 1; ++i) {
        cin >> start >> end;
        adj[start][end] = adj[end][start] = true;
    }

    if (n == 2) {
        cout << 0 << '\n' << 1 << '\n';
    }
    else if (n == 3) {
        cout << 1 << '\n' << 1 << '\n';
        for (int i = 1; i <= 3; ++i) {
            for (int j = i + 1; j <= 3; ++j) {
                if (!adj[i][j]) cout << i << ' ' << j << '\n';
            }
        }
    }
    else if (n == 4) {
        cout << 3 << '\n' << 1 << '\n';
        for (int i = 1; i <= 4; ++i) {
            for (int j = i + 1; j <= 4; ++j) {
                if (!adj[i][j]) cout << i << ' ' << j << '\n';
            }
        }
    }
    else {
        int num, cnt, base = 0;
        for (int i = 1; i <= n; ++i) {
            cnt = 0;
            for (int j = 1; j <= n; ++j) {
                if (!adj[i][j]) ++cnt;
            }
            if (base < cnt) {
                base = cnt;
                num = i;
            }
        }

        cout << base - 1 << ' ' << 2 << '\n';
        for (int i = 1; i <= n; ++i) {
            if (num != i && !adj[num][i]) cout << num << ' ' << i << '\n';
        }
    }
    
    return 0;
}