#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

vector<int> arr(10001, 0), aux(10001, 0);

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    aux[0] = 1;
    for (int i = 1; i <= 10000; ++i) aux[i] = i / 2 + 1;

    for (int i = 1; i <= 10000; ++i) {
        int temp = i;
        while (temp >= 0) {
            arr[i] += aux[temp];
            temp -= 3;
        }
    }

    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << arr[n] << '\n';
    }

    return 0;
}