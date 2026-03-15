#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> nums(N);
    int ans = 1e9;

    for (int i=0; i<N; i++) {
        cin >> nums[i];
    }

    int min_len = N + 1;
    int current_sum = 0;
    int left = 0;

    for (int right=0; right<N; right++) {
        current_sum += nums[right];
        while (current_sum >= S) {
            min_len = min(min_len, right-left+1);
            current_sum -= nums[left];
            left++;
        }
    }

    if (min_len == N + 1) {
        cout << 0 << '\n';
    } else {
        cout << min_len << '\n';
    }

    return 0;
}

