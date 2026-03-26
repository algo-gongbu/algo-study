#include <bits/stdc++.h>

using namespace std;

#define ll long long

int n, m, res, digit[10], thr[10], idx;
bool flag;

void f(int temp, int cnt) {
    if (cnt == 0) {
        if (temp < thr[0]) {res = temp; flag = true; return;}
    }

    for (int i = 9; i >= 0; --i) {
        if (cnt == idx && i == 0) return;
        
        if (digit[i]) {
            temp *= 10;
            temp += i;
            --digit[i];
            if (temp <= thr[cnt - 1]) f(temp, cnt - 1);
            if (flag) return;
            ++digit[i];
            temp /= 10;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;

    while (n) {
        if (m == 0) {cout << -1 << '\n'; return 0;}

        ++digit[n % 10];
        n /= 10;

        thr[idx++] = m;
        m /= 10;
    }

    if (m > 0) {
        for (int i = 9; i >= 0; --i) {
            while (digit[i]--) {
                res *= 10;
                res += i;
            }
        }

        cout << res << '\n';
    }
    else if (m == 0) {
        f(0, idx);

        if (flag) cout << res << '\n';
        else cout << -1 << '\n';
    }

    
    return 0;
}