#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()
#define square(n) ((n) * (n))

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll ab, ac, ad, bc, bd, cd;
    cin >> ab >> ac >> ad >> bc >> bd >> cd;

    // using Euler's tetrahedron formula (Volume expressed by the lengths of edges)
    ll x = square(ac) + square(ad) - square(cd);
    ll y = square(ab) + square(ac) - square(bc);
    ll z = square(ab) + square(ad) - square(bd);

    // Due to the precision issue, we have to use the 'long double' type
    long double v = sqrtl(4.0L * square(ab) * square(ac) * square(ad) 
                    - square(ab) * square(x) 
                    - square(ad) * square(y) 
                    - square(ac) * square(z) 
                    + x * y * z) / 12.0L;

    cout << fixed;
    cout.precision(4);
    cout << v << '\n';

    return 0;
}