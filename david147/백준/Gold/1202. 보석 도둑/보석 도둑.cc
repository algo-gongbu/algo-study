#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 3e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<pair<int, int>> jew;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        jew.push_back({b, a});
    }

    sort(jew.begin(), jew.end());
    
    multiset<int> bag;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        bag.insert(a);
    }

    long long res = 0;
    for (auto cur = jew.rbegin(); cur != jew.rend(); ++cur) {
        if (bag.size() == 0) break;

        auto pos = bag.lower_bound((*cur).second);
        if (pos == bag.end()) continue;
        else {
            res += (*cur).first;
            bag.erase(pos);
        }
    }
    cout << res << '\n';

    return 0;
}