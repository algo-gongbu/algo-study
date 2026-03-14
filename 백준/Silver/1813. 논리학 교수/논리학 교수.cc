#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6
#define mod (long long) 1e9

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[51];
deque<int> card;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        ++arr[m];
    }

    for (int i = 1; i <= n; ++i) {
        if (i == arr[i]) maximum = i;
    }

    if (maximum == INT_MIN) {
        if (arr[0] == 0) cout << 0 << '\n';
        else cout << -1 << '\n';
    }
    else cout << maximum << '\n';

    return 0;
}