#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 40
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
deque<int> q;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = n; i >= 1; --i) {
        if (i % 2) q.push_back(i);
        else q.push_front(i);
    }

    for (const int& elt : q) cout << elt << ' ';
    cout << '\n';

    return 0;
}