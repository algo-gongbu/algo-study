#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, in_ord[100000], post_ord[100000];

void f(int lb, int ub, int idx) {
    if (lb > ub) return;
    else if (lb == ub) {
        cout << in_ord[lb] << ' ';
        return;
    }
    int root = post_ord[idx];
    cout << root << ' ';

    int temp = lb;
    while (in_ord[temp] != root) ++temp;
    f(lb, temp - 1, idx - 1 - (ub - temp));
    f(temp + 1, ub, idx - 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> in_ord[i];
    for (int i = 0; i < n; ++i) cin >> post_ord[i];

    f(0, n - 1, n - 1);
    cout << '\n';

    return 0;
}