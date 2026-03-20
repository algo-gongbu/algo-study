#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 40
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<int> arr;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int left = (n + 1) / 2, right = n;
    for (int i = 1; i <= n; ++i) {
        if (i % 2) arr.push_back(left--);
        else arr.push_back(right--);
    }

    for (int i = 0; i < arr.size(); ++i) cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}