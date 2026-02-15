#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;

int mod = 1000000007;
long int f(long int base, long int exp) {
    if (exp <= 1) return base;
    
    long int temp = f(base, exp / 2) % mod;
    if (exp & 1) return (((temp * temp) % mod) * base) % mod;
    else return ((temp * temp) % mod);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long int n, m, h, ans = 0, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m >> h;
        ans += ((h * f(m, mod - 2)) % mod);
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}