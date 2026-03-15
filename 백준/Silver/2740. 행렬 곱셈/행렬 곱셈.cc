#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e5
#define mod (long long) 1e9

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int a[100][100], b[100][100], res[100][100];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    cin >> m >> h;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < h; ++j) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < m; ++k) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < h; ++j) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}