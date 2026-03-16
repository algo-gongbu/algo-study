#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> ropes(N);
    
    for (int i=0; i<N; i++) {
        cin >> ropes[i];
    }
    sort(ropes.begin(), ropes.end());
    
    int maxWeight = 0;
    for (int i=0; i<N; i++) {
        if (ropes[i]*(N-i) > maxWeight) {
            maxWeight = max(maxWeight, ropes[i]*(N-i));
        }
    }
    
    cout << maxWeight << "\n";

    return 0;
}