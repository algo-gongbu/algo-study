#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e5

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int num[1000000], arr[N + 1], score[N + 1];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> m;
        arr[i] = m;
        num[m] = i;
    }

    for (int i = 1; i <= n; i++) {
        m = arr[i];

        for (int j = m; j <= 1000000; j += m) {
            if (num[j] == 0) continue;

            score[i]++;
            score[num[j]]--;
        }
    }

    for (int i = 1; i <= n; i++) cout << score[i] << ' ';
    cout << '\n';

    return 0;
}