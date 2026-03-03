#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 5e2

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
bool is_prime[4000001];
int prime[300000], idx;

void f() {
    queue<int> q;
    q.push(2);

    int sum, index, size;
    for (int i = 1; i < idx; i++) {
        size = q.size();

        for (int j = 0; j < size; j++) {
            sum = q.front();
            q.pop();

            if (sum == n) ans++;
            else if (sum < n) q.push(sum + prime[i]);
        }

        q.push(prime[i]);
    }

    while (!q.empty()) {
        if (q.front() == n) ans++;
        q.pop();
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 2; i < 4000000; i++) {
        if (is_prime[i]) continue;

        prime[idx++] = i;
        for (int j = i + i; j <= 4000000; j += i) is_prime[j] = true;
    }

    cin >> n;

    f();

    cout << ans << '\n';

    return 0;
}