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

    a = line[0].first, b = line[0].second;
    for (int i = 1; i < n; ++i) {
        if (line[i].first > b) {
            ans += b - a;
            a = line[i].first, b = line[i].second;
        }
        else {
            b = max(b, line[i].second);
        }
    }
    ans += b - a;

    cout << ans << '\n';

    return 0;
}