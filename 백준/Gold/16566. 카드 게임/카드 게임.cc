#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N (int) 4e6

int parent[N + 1];

int find(int n) {
    if (parent[n] == n) return n;
    else {
        parent[n] = find(parent[n]);
        return parent[n];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, k, temp;
    cin >> n >> m >> k;

    vector<int> hand;
    for (int i = 0; i < m; ++i) {
        cin >> temp;
        parent[temp] = temp;
        hand.push_back(temp);
    }
    sort(hand.begin(), hand.end());

    while (k--) {
        cin >> temp;
        int val = *upper_bound(hand.begin(), hand.end(), temp);
        val = find(val);
        cout << val << '\n';
        parent[val] = find(*upper_bound(hand.begin(), hand.end(), val));
    }

    return 0;
}