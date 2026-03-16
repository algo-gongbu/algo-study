#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e5
#define mod (long long) 1e9

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[2200][2200], res[3];

void f(int y, int x, int size) {
    if (size == 1) return;
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            f(y + i * size / 3, x + j * size / 3, size / 3);
        }
    }

    flag = false;
    int base = arr[y][x];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (arr[y + i * size / 3][x + j * size / 3] == -1 || arr[y + i * size / 3][x + j * size / 3] != base) {
                flag = true;
                break;
            }
        }
    }

    if (flag) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (arr[y + i * size / 3][x + j * size / 3] == -1) continue;
                else ++res[arr[y + i * size / 3][x + j * size / 3]];
            }
        }
        arr[y][x] = -1;
    }
    else {
        if (size == n) ++res[arr[y][x]];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> m;
            arr[i][j] = m + 1;
        }
    }

    if (n == 1) ++res[arr[0][0]];
    else f(0, 0, n);

    for (int i = 0; i < 3; ++i) cout << res[i] << '\n';
    
    return 0;
}