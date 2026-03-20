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

    cin >> n;
    string text, res = "";
    cin >> text;
    for (int i = 0; i < n; ++i) res += text;
    cout << res << '\n';

    return 0;
}