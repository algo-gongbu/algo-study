#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int a[100], b[100], c[100], idx, idx_a, idx_b;

void f() {
    int ia = idx_a, ib = idx_b, c_max = INT_MIN;
    for (int i = ia; i < n; i++) {
        if (c_max >= a[i]) continue;

        for (int j = ib; j < m; j++) {
            if (a[i] == b[j]) {
                c_max = a[i];
                idx_a = i + 1;
                idx_b = j + 1;
                break;
            }
        }
    }

    if (c_max == INT_MIN) flag = true;
    else c[idx++] = c_max;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];

    while (!flag) f();

    cout << idx << '\n';
    for (int i = 0; i < idx; i++) cout << c[i] << ' ';
    cout << '\n';

    return 0;
}