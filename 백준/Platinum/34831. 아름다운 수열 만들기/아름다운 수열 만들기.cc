#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string base = "0 1 2 0 1 2", arr = "" + base;

    int n; 
    cin >> n;

    if ((n - 6) % 5 != 0) {cout << "No" << '\n'; return 0;}

    int idx = (n - 6) / 5;
    while (idx--) {
        reverse(base.begin(), base.end());
        arr.replace(arr.size() - 1, base.size(), base);
    }

    cout << "Yes" << '\n' << arr << '\n';

    return 0;
}