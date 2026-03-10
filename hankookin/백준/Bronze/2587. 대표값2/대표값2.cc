#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int nums[5];
    cin >> nums[0] >> nums[1] >> nums[2] >> nums[3] >> nums[4];
    sort(nums, nums+5);

    cout << (nums[0]+nums[1]+nums[2]+nums[3]+nums[4])/5 << "\n";
    cout << nums[2] << "\n";

    return 0;
}