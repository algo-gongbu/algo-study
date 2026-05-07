#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

struct Shark {
    int s, d, z;
};

vector<vector<pair<vector<Shark>, vector<Shark>>>> board;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int r, c, m;
    cin >> r >> c >> m;
    board.resize(r);
    for (int i = 0; i < r; ++i) board[i].resize(c);

    int y, x, s, d, z;
    for (int i = 0; i < m; ++i) {
        Shark temp;
        cin >> y >> x >> s >> d >> z;
        if (d == 1 || d == 2) s %= (2 * (r - 1));
        else if (d == 3 || d == 4) s %= (2 * (c - 1));
        temp.s = s, temp.d = d, temp.z = z;
        board[y - 1][x - 1].first.push_back(temp);
    }

    int ans = 0;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (!board[j][i].first.empty()) {
                ans += board[j][i].first[0].z;
                board[j][i].first.pop_back();
                break;
            }
        }

        for (int y = 0; y < r; ++y) {
            for (int x = 0; x < c; ++x) {
                if (!board[y][x].first.empty()) {
                    Shark cur = board[y][x].first[0];
                    board[y][x].first.pop_back();
                    int nxt_y = y, nxt_x = x, speed = cur.s;

                    while (speed--) {
                        if (cur.d == 1) {
                            if (nxt_y == 0) {cur.d = 2; nxt_y++;}
                            else nxt_y--;
                        }
                        else if (cur.d == 2) {
                            if (nxt_y == r - 1) {cur.d = 1; nxt_y--;}
                            else nxt_y++;
                        }
                        else if (cur.d == 3) {
                            if (nxt_x == c - 1) {cur.d = 4; nxt_x--;}
                            else nxt_x++;
                        }
                        else if (cur.d == 4) {
                            if (nxt_x == 0) {cur.d = 3; nxt_x++;}
                            else nxt_x--;
                        }
                    }

                    board[nxt_y][nxt_x].second.push_back(cur);
                }
            }
        }

        for (int y = 0; y < r; ++y) {
            for (int x = 0; x < c; ++x) {
                if (!board[y][x].second.empty()) {
                    int idx = board[y][x].second.size();
                    Shark maximum = board[y][x].second[0];
                    while (--idx) {
                        if (board[y][x].second[idx].z > maximum.z) maximum = board[y][x].second[idx];
                        board[y][x].second.pop_back();
                    }
                    board[y][x].second.pop_back();

                    board[y][x].first.push_back(maximum);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}