#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int acc1[N + 1], acc2[N + 1];
vector<int> sub_sum;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> h;
    cin >> n;
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        acc1[i] = acc1[i - 1] + temp;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> temp;
        acc2[i] = acc2[i - 1] + temp;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i - 1; j >= 0; j--) {
            sub_sum.push_back(acc2[i] - acc2[j]);
        }
    }

    sort(sub_sum.begin(), sub_sum.end());

    long long res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            temp = acc1[i] - acc1[j];

            auto lb = lower_bound(sub_sum.begin(), sub_sum.end(), h - temp);
            auto ub = upper_bound(sub_sum.begin(), sub_sum.end(), h - temp);

            res += ub - lb;
        }
    }

    cout << res << '\n';

    return 0;
}