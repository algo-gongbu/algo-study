#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 3e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
char board[1000][1000];
bool visited[1000][1000];
int id[1000][1000], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, idx = 1000001;
map<int, int> id_to_cnt;

void f() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '0' && !visited[i][j]) {
                queue<pair<int, int>> q;
                q.push({i, j});

                int cur_y, cur_x, new_y, new_x, cnt = 0;
                while (!q.empty()) {
                    cur_y = q.front().first;
                    cur_x = q.front().second;
                    q.pop();

                    if (visited[cur_y][cur_x]) continue;
                    visited[cur_y][cur_x] = true;
                    cnt++;

                    for (int k = 0; k < 4; ++k) {
                        new_y = cur_y + dy[k];
                        new_x = cur_x + dx[k];

                        if (new_y >= n || new_y < 0 || new_x >= m || new_x < 0) continue;

                        if (!visited[new_y][new_x] && board[new_y][new_x] == '0') {
                            id[new_y][new_x] = idx;
                            q.push({new_y, new_x});
                        }
                    }
                }

                id_to_cnt[idx] = cnt;
                id[i][j] = idx++;
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }    

    f();

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << res[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << id[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    vector<int> val_id;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == '0') cout << 0;
            else {
                int new_i, new_j, cnt = 1;
                for (int k = 0; k < 4; ++k) {
                    new_i = i + dy[k];
                    new_j = j + dx[k];

                    if (new_i >= n || new_i < 0 || new_j >= m || new_j < 0) continue;

                    flag = false;
                    for (int l = 0; l < val_id.size(); ++l) {
                        if (id[new_i][new_j] == val_id[l]) {flag = true; break;}
                    } 

                    if (!flag) {
                        cnt += id_to_cnt[id[new_i][new_j]];
                        val_id.push_back(id[new_i][new_j]);
                    }
                }
                cout << cnt % 10;
                val_id.clear();
            }
        }
        cout << '\n';
    }

    return 0;
}