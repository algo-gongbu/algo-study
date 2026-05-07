#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    if (m == 0) {cout << "stay\n"; return 0;}

    vector<pair<int, pair<int, int>>> arr;
    int c, x, h;
    for (int i = 0; i < m; ++i) {
        cin >> c >> x >> h;
        arr.push_back({x, {c, h}});
    }
    sort(all(arr));

    int cur = 0;
    if (arr[0].second.first == 0) {
        if (arr[0].second.second >= cur) cur = arr[0].second.second + 1;
        else cur = max(cur - arr[0].first, arr[0].second.second + 1);
        
    }
    else {
        cur -= arr[0].first;
        if (cur >= arr[0].second.second) {cout << "adios\n"; return 0;}
    }

    for (int i = 1; i < m; ++i) {
        if (arr[i].second.first == 0) {
            if (arr[i].second.second >= cur) cur = arr[i].second.second + 1;
            else cur = max(cur - (arr[i].first - arr[i - 1].first), arr[i].second.second + 1);
        }
        else {
            cur -= (arr[i].first - arr[i - 1].first);
            if (cur >= arr[i].second.second) {cout << "adios\n"; return 0;}
        }
    }

    cur -= (n - arr[m - 1].first);

    if (cur <= 0) cout << "stay\n";
    else cout << "adios\n";

    return 0;
}