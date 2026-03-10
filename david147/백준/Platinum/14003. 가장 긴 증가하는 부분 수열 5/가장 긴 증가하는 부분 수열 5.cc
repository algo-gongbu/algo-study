#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<int> memo, idx, res;
int arr[N];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        auto pos = lower_bound(memo.begin(), memo.end(), arr[i]);
        if (pos == memo.end()) {
            memo.push_back(arr[i]);
            idx.push_back(memo.size() - 1);
        }
        else {
            int temp = pos - memo.begin();
            memo[temp] = arr[i];
            idx.push_back(temp);
        }

        // for (int temp: memo) cout << temp << ' ';
        // cout << '\n';
    }

    int cnt = memo.size() - 1;
    for (int i = n - 1; i >= 0; --i) {
        if (idx[i] == cnt) {
            res.push_back(arr[i]);
            --cnt;
        }
        
        if (cnt < 0) break;
    }
    reverse(res.begin(), res.end());
    
    cout << memo.size() << '\n';
    for (int elt : res) cout << elt << ' ';
    cout << '\n';

    return 0;
}