#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> sorted(n);

    for (int i=0; i<n; i++) {
        cin >> nums[i];
        sorted[i] = nums[i];
    }
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(),sorted.end()), sorted.end());
    
    for (int i=0; i<n; i++) {
        auto it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
        cout << distance(sorted.begin(), it) << " ";
    }
    
    return 0;
}