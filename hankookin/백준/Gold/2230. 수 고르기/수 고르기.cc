#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<long long> nums(N);
    for (int i=0; i<N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int ans = 2000000001;
    int left = 0, right = 0;

    while (right < N) {
        long long diff = nums[right] - nums[left];

        if (diff >= M) {
            ans = min(ans, (int)diff);
            left++;
        } 
        else {
            right++;
        }
        if (left > right) right = left;
    }

    cout << ans << "\n";

    return 0;
}