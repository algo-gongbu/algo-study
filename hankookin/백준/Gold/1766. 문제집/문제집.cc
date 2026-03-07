#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N+1);
    vector<int> indegree(N+1, 0);

    for (int i=0; i<M; i++) {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        indegree[B]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=1; i<=N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        cout << curr << " ";

        for (int next : adj[curr]) {
            indegree[next]--;
            if (indegree[next] == 0) {
                pq.push(next);
            }
        }
    }

    return 0;
}