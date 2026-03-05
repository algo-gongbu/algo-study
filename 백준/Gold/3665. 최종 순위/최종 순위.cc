#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 500

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<int> in_deg(N + 1, 0), res;
int ranking[500];
bool adj[501][501];

void f() {
    queue<int> q;
    res.clear();

    for (int i = 1; i <= m; i++) {
        if (in_deg[i] == 0) q.push(i);
    }

    int cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i = 1; i <= m; i++) {
            if (adj[cur][i]) {
                if (--in_deg[i] == 0) q.push(i);
            }
        } 

        res.push_back(cur);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int t1, t2;
    for (int i = 0; i < n; i++) {
        cin >> m;

        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                adj[j][k] = false;
            }
            in_deg[j] = 0;
        }

        for (int j = 0; j < m; j++) cin >> ranking[j];

        for (int j = 0; j < m - 1; j++) {
            for (int k = j + 1; k < m; k++) {
                adj[ranking[j]][ranking[k]] = true;
                in_deg[ranking[k]]++;
            }
        }

        cin >> h;
        for (int j = 0; j < h; j++) {
            cin >> t1 >> t2; 
            if (adj[t1][t2]) {
                adj[t1][t2] = false;
                in_deg[t2]--; 
                adj[t2][t1] = true;
                in_deg[t1]++;
            }
            else if (adj[t2][t1]) {
                adj[t2][t1] = false;
                in_deg[t1]--; 
                adj[t1][t2] = true;
                in_deg[t2]++;
            }
        }

        f();
    
        if (res.size() < m) cout << "IMPOSSIBLE\n";
        else {
            for (int j = 0; j < m; j++) cout << res[j] << ' ';
            cout << '\n';
        }
    }
    

    return 0;
}