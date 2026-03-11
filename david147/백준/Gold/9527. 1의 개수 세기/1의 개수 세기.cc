#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long res;

long long f(long long n) {
    if (n <= 0) return 0;
    int pow = 0;
    while ((1LL << (pow + 1)) <= n) ++pow;

    long long temp = 0;
    for (int i = 0; i < pow; ++i) temp += i * (1LL << (i - 1)) + (1LL << i);
    temp += n - (1LL << pow) + 1;
    temp += f(n - (1LL << pow));
    return temp;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, b;
    cin >> a >> b;
    
    res = f(b) - f(a - 1);

    cout << res << '\n';

    return 0;
}