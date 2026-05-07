#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M; cin >> N >> M;
    vector<int> nums(N);
    for (int i=0; i<N; i++) {
        cin >> nums[i];
    }

    int count = 0;
    for (int i=0; i<N; i++) {
        int idx = i;
        int sum = 0;
        while (idx < N && sum != M) {
            sum += nums[idx];
            idx++;
        }
        if (sum == M) {
            count++;
        }
    }
    
    cout << count << "\n";

    return 0;
}