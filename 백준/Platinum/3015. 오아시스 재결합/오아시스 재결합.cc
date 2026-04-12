#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    ll res = 0;
    stack<pair<int, int>> s; // monotonic stack
    for (int i = 0; i < n; ++i) {
        int cur = arr[i], cnt = 1;
        
        while (!s.empty() && s.top().first <= cur) {
            res += s.top().second;
            
            if (s.top().first == cur) cnt += s.top().second;

            s.pop();
        }

        if (!s.empty()) res += 1;

        s.push({cur, cnt});
    }

    cout << res << '\n';
        
    return 0;
}