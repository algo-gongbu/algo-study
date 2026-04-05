#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    vector<pair<ll, int>> arr(n);
    ll temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        arr[i] = {temp, i + 1};
    }
    sort(all(arr));

    ll score = 3 * arr[n - 1].first, acc = arr[n - 1].first, idx = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        acc += arr[i].first;
        ll cur = arr[n - 1].first + arr[i].first + acc;
        // cout << cur << '\n';
        if (score < cur) {
            score = cur;
            idx = i;
        }
    }

    cout << n - idx << '\n';
    for (int i = n - 1; i >= idx; --i) cout << arr[i].second << ' ';
    cout << '\n';

    return 0;
}