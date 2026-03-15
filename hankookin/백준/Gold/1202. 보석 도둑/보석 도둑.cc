#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> jewels(N);
    vector<int> bags(K);

    for (int i=0; i<N; i++) {
        cin >> jewels[i].first >> jewels[i].second;
    }
    for (int i=0; i<K; i++) {
        cin >> bags[i];
    }

    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());

    priority_queue<int> pq;
    int idx = 0;
    long long ans = 0;
    for (int i=0; i<K; i++) {
        while (idx<N && jewels[idx].first <= bags[i]) {
            pq.push(jewels[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}

