#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 5e2

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
char board[1000][1000];
int visited[1000][1000];
int idx = 1;

void f() {
    int y, x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;

            ans++;
            y = i, x = j;
            while (!visited[y][x]) {
                visited[y][x] = idx;

                if (board[y][x] == 'U') y--;
                else if (board[y][x] == 'D') y++;
                else if (board[y][x] == 'L') x--;
                else if (board[y][x] == 'R') x++;
            }
            
            if (visited[y][x] != idx) ans--;
            idx++;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    f();

    cout << ans << '\n';

    return 0;
}