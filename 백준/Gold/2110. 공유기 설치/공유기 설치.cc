#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<int> stall;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> h;
        stall.push_back(h);
    }

    sort(stall.begin(), stall.end());
    
    int left = 1, right = stall[stall.size() - 1] - stall[0], mid, cnt, prev, idx, res;
    while (left <= right) {
        mid = (left + right) / 2;
        
        cnt = 1, prev = stall[0], idx = 1;
        while (idx < stall.size()) {
            if (stall[idx] - prev >= mid) {
                ++cnt;
                prev = stall[idx];
            }
            ++idx;
        }

        if (cnt >= m) {res = mid; left = mid + 1;}
        else right = mid - 1;
    }

    cout << res << '\n';

    return 0;
}