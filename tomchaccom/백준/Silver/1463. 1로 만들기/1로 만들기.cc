#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;

    cin >> n;
    vector<int> dp(n+1);

    dp[1] = 0;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i -1] + 1;

        if(i % 2 == 0) dp[i] = min(dp[i / 2] + 1, dp[i]);
        if(i % 3 == 0) dp[i] = min(dp[i / 3] + 1, dp[i]);
    }
    cout << dp[n];
}