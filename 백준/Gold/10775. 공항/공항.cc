#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int plane[N + 1];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    set<int> gates;
    for (int i = 1; i <= n; i++) gates.insert(gates.end(), i);

    for (int i = 1; i <= m; i++) cin >> plane[i];

    for (int i = 1; i <= m; i++) {
        auto gate = gates.upper_bound(plane[i]);
        if (gate != gates.begin()) {
            gates.erase(--gate);
            ans++;
        }
        else break;
    }

    cout << ans << '\n';

    return 0;
}