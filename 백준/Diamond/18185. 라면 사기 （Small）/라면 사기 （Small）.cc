#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> factories(N);
    for (int i=0; i<N; i++) {
        cin >> factories[i];
    }

    long long cost = 0;
    int idx = 0;
    bool isMultiple;
    while (idx < N) {
        if (factories[idx] == 0) {
            idx++;
            continue;
        }

        if (idx+2 < N && factories[idx] > 0 && factories[idx+1] > 0 && factories[idx+2] > 0) {
            if (factories[idx+1] > factories[idx+2]) {
                int diff = min(factories[idx], factories[idx+1]-factories[idx+2]);
                cost += 5 * diff;
                factories[idx] -= diff;
                factories[idx+1] -= diff;
            }
            if (factories[idx] == 0) continue;
            
            factories[idx]--; factories[idx+1]--; factories[idx+2]--;
            cost += 7;
        }
        else if (idx+1 < N && factories[idx] > 0 && factories[idx+1] > 0) {
            factories[idx]--; factories[idx+1]--;
            cost += 5;
        }
        else {
            factories[idx]--;
            cost += 3;
        }
    }

    cout << cost << '\n';

    return 0;
}