#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6
#define mod (long long) 1e9

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
vector<pair<int, int>> line;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        line.push_back({a, b});
    }
    sort(line.begin(), line.end());

    multiset<int> r;
    for (auto pos = line.begin(); pos != line.end(); ++pos) {
        while (r.size() > 0 && (*pos).first >= *(r.begin())) {r.erase(r.begin());}
        r.insert((*pos).second);
        maximum = max(maximum, (int) r.size());
    }

    cout << maximum << '\n';

    return 0;
}