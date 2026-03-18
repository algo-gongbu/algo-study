#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
char gear[4][8], temp;
int dir[4];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> gear[i][j];
        }
    }

    cin >> n;
    int idx;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) dir[j] = 0;
        cin >> m >> h;
        dir[m - 1] = h;

        idx = m - 1;
        while (idx - 1 >= 0 && gear[idx - 1][2] != gear[idx][6]) {
            dir[idx - 1] = -dir[idx]; --idx;
        } 

        idx = m - 1;
        while (idx + 1 < 4 && gear[idx][2] != gear[idx + 1][6]) {
            dir[idx + 1] = -dir[idx]; ++idx;
        }

        for (int j = 0; j < 4; ++j) {
            if (dir[j] == 1) {
                temp = gear[j][7];
                for (int k = 7; k > 0; --k) gear[j][k] = gear[j][k - 1];
                gear[j][0] = temp;
            }
            else if (dir[j] == -1) {
                temp = gear[j][0];
                for (int k = 0; k < 7; ++k) gear[j][k] = gear[j][k + 1];
                gear[j][7] = temp;
            }
        }

        // for (int j = 0; j < 4; ++j) cout << dir[j] << ' ';
        // cout << '\n';
    }
    
    for (int i = 0; i < 4; ++i) {
        if (gear[i][0] == '1') ans += (1 << i);
    }

    // for (int i = 0; i < 4; ++i) {
    //     for (int j = 0; j < 8; ++j) {
    //         cout << gear[i][j];
    //     }
    //     cout << '\n';
    // }

    cout << ans << '\n';

    return 0;
}