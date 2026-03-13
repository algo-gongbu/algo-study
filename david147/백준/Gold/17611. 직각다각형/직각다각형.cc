#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5
#define mod (long long) 1e9

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
vector<pair<int, int>> line_h, line_v;
int point[N][2];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> point[i][0] >> point[i][1];
    for (int i = 1; i < n; ++i) {
        if (point[i][0] == point[i - 1][0]) line_v.push_back({min(point[i][1], point[i - 1][1]), max(point[i][1], point[i - 1][1])});
        if (point[i][1] == point[i - 1][1]) line_h.push_back({min(point[i][0], point[i - 1][0]), max(point[i][0], point[i - 1][0])});
    }
    if (point[0][0] == point[n - 1][0]) line_v.push_back({min(point[0][1], point[n - 1][1]), max(point[0][1], point[n - 1][1])});
    if (point[0][1] == point[n - 1][1]) line_h.push_back({min(point[0][0], point[n - 1][0]), max(point[0][0], point[n - 1][0])});
    
    sort(line_h.begin(), line_h.end());
    sort(line_v.begin(), line_v.end());

    multiset<int> r;
    for (auto pos = line_v.begin(); pos != line_v.end(); ++pos) {
        while (r.size() > 0 && (*pos).first >= *(r.begin())) {r.erase(r.begin());}
        r.insert((*pos).second);
        maximum = max(maximum, (int) r.size());
    }
    r.clear();
    for (auto pos = line_h.begin(); pos != line_h.end(); ++pos) {
        while (r.size() > 0 && (*pos).first >= *(r.begin())) {r.erase(r.begin());}
        r.insert((*pos).second);
        maximum = max(maximum, (int) r.size());
    }

    cout << maximum << '\n';

    return 0;
}