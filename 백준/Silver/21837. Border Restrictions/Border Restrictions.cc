#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
map<string, vector<string>> adj;
map<string, int> res;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin.ignore();

    string dest, origin, temp, line, start;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        stringstream ss(line);

        ss >> dest;
        res[dest] = 0;
        if (i == 0) start = dest;
        
        for (int j = 0; j < 3; ++j) ss >> temp;
        
        while (ss >> origin) {
            adj[origin].push_back(dest);
        }
    }

    int week;
    queue<pair<string, int>> q;
    q.push({start, 1});
    res[start] = 1;

    while (!q.empty()) {
        temp = q.front().first;
        week = q.front().second;
        q.pop();

        for (const string& elt : adj[temp]) {
            if (res[elt] == 0) {
                res[elt] = week + 1;
                q.push({elt, week + 1});
            }
        }
    }

    for (const auto& p : res) {
        cout << p.second << '\n';
    }

    return 0;
}