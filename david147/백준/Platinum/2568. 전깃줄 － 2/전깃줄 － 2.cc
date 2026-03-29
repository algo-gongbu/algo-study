#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(v) v.begin(), v.end()

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int start, end, cur;
    vector<pair<int, int>> line;
    for (int i = 0; i < n; ++i) {
        cin >> start >> end;
        line.push_back({start, end});
    }
    sort(all(line));

    vector<int> memo, idx;
    for (int i = 0; i < n; ++i) {
        // for (const int& elt : memo) cout << elt << ' ';
        // cout << '\n';

        cur = line[i].second;
        auto pos = lower_bound(all(memo), cur);
        if (pos == memo.end()) {
            idx.push_back(memo.size());
            memo.push_back(cur);
        }
        else {
            idx.push_back(pos - memo.begin());
            memo.insert(memo.erase(pos), cur);
        }
    }
    // cout << memo.size() << '\n';
    // for (const int& elt: idx) cout << elt << ' ';
    // cout << '\n';

    vector<int> res;
    int temp = memo.size() - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (idx[i] == temp) --temp;
        else res.push_back(line[i].first);
    }
    reverse(all(res));

    cout << res.size() << '\n';
    for (const int& elt: res) cout << elt << '\n';

    return 0;
}