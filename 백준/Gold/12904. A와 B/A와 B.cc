#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string from, to;
    cin >> from >> to;

    char cur;
    while (to.size() > from.size()) {
        cur = to[to.size() - 1];
        to = to.substr(0, to.size() - 1);
        if (cur == 'B') reverse(to.begin(), to.end());
    }

    if (to == from) cout << 1 << '\n';
    else cout << 0 << '\n';

    return 0;
}