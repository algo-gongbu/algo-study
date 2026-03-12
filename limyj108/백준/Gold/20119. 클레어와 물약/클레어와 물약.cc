#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, L, K, x, y, ans = 0;
    queue<int> q;
    cin >> N >> M;

    vector<int> results(M);                 // results[i]: i번째 레시피의 결과 물약
    vector<int> cnt(M);                     // cnt[i]: i번째 레시피를 위해 남은 재료 수
    vector<vector<int>> ingredients(N + 1); // ingredients[i]: i를 재료로 사용하는 레시피 #의 vector
    vector<bool> visited(N + 1, false);     // visited[i]: 물약 #i를 만들었는지 여부

    for (int m = 0; m < M; m++) {
        cin >> K;
        cnt[m] = K;
        for (int k = 0; k < K; k++) {
            cin >> x;
            ingredients[x].push_back(m);
        }
        cin >> results[m];
    }

    cin >> L;
    for (int l = 0; l < L; l++) {
        cin >> y;
        q.push(y);
        visited[y] = true;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        ans++;

        for (int recipe_id : ingredients[cur]) {
            cnt[recipe_id]--;
            if (cnt[recipe_id] == 0) {
                if (!visited[results[recipe_id]]) {
                    q.push(results[recipe_id]);
                    visited[results[recipe_id]] = true;
                }
            }
        }
    }

    cout << ans << "\n";
    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            cout << i << " ";
        }
    }

    return 0;
}