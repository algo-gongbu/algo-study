#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> nums(N);
    for (int i=0; i<N; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());

    int count = 0;
    for (int i=0; i<N; i++) {
        long long target = nums[i];
        int left = 0, right = N-1;

        while (left < right) {
            if (left == i) {
                left++;
                continue;
            }
            if (right == i) {
                right--;
                continue;
            }
            long long sum = nums[left] + nums[right];

            if (sum == target) {
                count++;
                break;
            } else if (sum < target) {
                left ++;
            } else {
                right--;
            }
        }
    }

    cout << count << '\n';

    return 0;
}