#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int ccw(pair<int, int>& a, pair<int, int>& b, pair<int, int> &c) {
    ll val = 1LL * (b.first - a.first) * (c.second - b.second) - 1LL * (b.second - a.second) * (c.first - b.first);
    if (val > 0) return 1;
    else if (val < 0) return -1;
    else return 0;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<pair<int, int>> point(n);
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        point[i] = {x, y};
    }
    sort(all(point));

    vector<pair<int, int>> hull;
    hull.push_back(point[0]); hull.push_back(point[1]);
    for (int i = 2; i < n; ++i) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull[hull.size() - 1], point[i]) <= 0) hull.pop_back();
        hull.push_back(point[i]);

        // for (auto& elt: hull) cout << elt.first << ' ' << elt.second << '\n';
        // cout << '\n';
    }

    int lower_size = hull.size();
    for (int i = n - 1; i >= 0; --i) {
        while (hull.size() > lower_size && ccw(hull[hull.size() - 2], hull[hull.size() - 1], point[i]) <= 0) hull.pop_back();
        hull.push_back(point[i]);
        
        // for (auto& elt: hull) cout << elt.first << ' ' << elt.second << '\n';
        // cout << '\n';
    }

    hull.pop_back(); // the starting point is the same as the ending point

    cout << hull.size() << '\n';

    return 0;
}