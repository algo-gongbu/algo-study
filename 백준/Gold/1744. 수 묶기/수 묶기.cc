#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> pos;
    vector<int> neg;
    int zeroes = 0, ones = 0;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        if (num == 1) ones++;
        else if (num > 0) pos.push_back(num);
        else if (num < 0) neg.push_back(num);
        else zeroes++;
    }
    
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    
    int result = 0;
    while (!pos.empty() && pos.size() >= 2) {
        result += pos[0] * pos[1];
        pos.erase(pos.begin());
        pos.erase(pos.begin());
    }
    while (!neg.empty() && neg.size() >= 2) {
        result += neg[0] * neg[1];
        neg.erase(neg.begin());
        neg.erase(neg.begin());
    }
    if (!pos.empty()) result += pos[0];
    if (!neg.empty() && zeroes == 0) result += neg[0];
    result += ones;

    cout << result << "\n";

    return 0;
}