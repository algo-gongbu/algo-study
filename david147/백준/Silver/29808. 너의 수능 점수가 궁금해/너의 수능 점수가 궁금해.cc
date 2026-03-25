#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    if (n % 4763 != 0) {cout << 0 << '\n'; return 0;}

    n /= 4763;
    vector<pair<int, int>> res;
    for (int i = 0; i <= 200; ++i) {
        for (int j = 0; j <= 200; ++j) {
            if ((508 * i + 305 * j) == n) {res.push_back({i, j}); continue;}
            if ((508 * i + 212 * j) == n) {res.push_back({i, j}); continue;}
            if ((108 * i + 305 * j) == n) {res.push_back({i, j}); continue;}
            if ((108 * i + 212 * j) == n) {res.push_back({i, j}); continue;}
        }
    }

    cout << res.size() << '\n';
    if (res.size()) {
        for (const auto& p : res) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }

    return 0;
}