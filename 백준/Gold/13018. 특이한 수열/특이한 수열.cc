#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 40
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    if (m == n) {
        cout << "Impossible\n";
        return 0;
    }

    vector<int> arr;
    arr.push_back(n - m);
    for (int i = 1; i < n - m; ++i) arr.push_back(i);
    for (int i = n - m + 1; i <= n; ++i) arr.push_back(i);

    for (const int& elt: arr) cout << elt << ' ';
    cout << '\n';
    
    return 0;
}