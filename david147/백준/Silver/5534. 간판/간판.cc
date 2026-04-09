#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    string target, cur;
    cin >> target;

    int ans = 0;
    bool flag;
    while (n--) {
        cin >> cur;

        for (int i = 0; i < cur.size(); ++i) {
            if (cur[i] == target[0]) {
                for (int j = 1; i + (target.size() - 1) * j < cur.size(); ++j) {
                    flag = true;
                    for (int k = 1; k < target.size(); ++k) {
                        if (cur[i + k * j] != target[k]) flag = false;
                    }
                    if (flag) {++ans; break;}
                }
                if (flag) break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}