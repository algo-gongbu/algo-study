#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    int nums[N];
    for (int i=0; i<N; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+N);

    int left = 0, right = N-1;
    int sum = 2e9+7, left_ans = 0, right_ans = 0;
    while (left < right) {
        int currSum = nums[left] + nums[right];
        if (abs(currSum) < abs(sum)) {
            sum = currSum;
            left_ans = nums[left];
            right_ans = nums[right];
        }
        if (currSum == 0) break;

        if (currSum < 0) left++;
        else right--;
    }

    cout << left_ans << " " << right_ans << "\n";

    return 0;
}