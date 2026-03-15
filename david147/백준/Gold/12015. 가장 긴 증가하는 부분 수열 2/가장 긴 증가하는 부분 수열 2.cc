#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
set<int> memo;
vector<int> res;

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (memo.find(m) != memo.end()) continue;

        auto pos = memo.upper_bound(m);
        if (pos == memo.end()) {
            memo.insert(memo.end(), m);
            res.push_back(m);
        }
        else memo.insert(memo.erase(pos), m);

        // for (int temp: memo) cout << temp << ' ';
        // cout << '\n';
    }

    cout << memo.size() << '\n';
    // for (int temp: memo) cout << temp << ' ';
    // cout << '\n';
    // for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';
    // cout << '\n'; 

    return 0;
}