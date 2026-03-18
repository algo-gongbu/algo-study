#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
string rps[10];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    set<char> game;
    char target, cnt;
    int winner;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) cin >> rps[j];

        vector<bool> is_lose(m, false);
        for (int j = 0; j < rps[0].size(); ++j) {
            for (int k = 0; k < m; ++k) {
                if (!is_lose[k]) game.insert(rps[k][j]);
            }

            if (game.size() == 2) {
                if (*game.begin() == 'P') {
                    if (*(--game.end()) == 'R') target = 'R';
                    else if (*(--game.end()) == 'S') target = 'P';
                }
                else if (*game.begin() == 'R') {
                    if (*(--game.end()) == 'S') target = 'S';
                }

                for (int k = 0; k < m; ++k) {
                    if (!is_lose[k] && rps[k][j] == target) is_lose[k] = true;
                }
            }
            game.clear();
        }

        cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (is_lose[j]) ++cnt;
            else winner = j + 1;
        }

        if (cnt == m - 1) cout << winner << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}