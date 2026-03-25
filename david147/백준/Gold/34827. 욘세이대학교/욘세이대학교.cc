#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x = 0, y = 0;
    string prefix;
    cin >> n >> prefix;

    vector<bool> used(26, false);
    for (int i = 0; i < n; ++i) used[prefix[i] - 'A'] = true;

    for (int i = 0; i < n - 1; ++i) {
        if (prefix[i] < prefix[i + 1]) ++x;
        else if (prefix[i] > prefix[i + 1]) ++y;
    }

    if (abs(x - y) <= 1) cout << prefix.size() << '\n' << prefix << '\n';
    else {
        char idx, nxt;
        bool flag;

        while (abs(x - y) > 1) {
            idx = prefix[prefix.size() - 1] - 'A';
            flag = false;

            if (x > y) {
                while (used[idx]) {
                    --idx;
                    if (idx < 0) {idx = 25; flag = true;}
                }
                if (flag) ++x;
                else ++y;
            }
            else {
                while (used[idx]) {
                    ++idx;
                    if (idx >= 26) {idx = 0; flag = true;}
                }
                if (flag) ++y;
                else ++x;
            }

            nxt = 'A' + idx;
            prefix += nxt;
            used[idx] = true;
        }
        
        cout << prefix.size() << '\n' << prefix << '\n';
    }

    return 0;
}