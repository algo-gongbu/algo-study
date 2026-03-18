#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<vector<char>> nums;
    for (int i=0; i<N; i++) {
        int num;
        cin >> num;
        string numStr = to_string(num);
        vector<char> chars;
        for (char c : numStr) {
            chars.push_back(c);
        }
        nums.push_back(chars);
    }
    
    sort(nums.begin(), nums.end(), [](const vector<char>& a, const vector<char>& b) {
        vector<char> ab = a;
        ab.insert(ab.end(), b.begin(), b.end());

        vector<char> ba = b;
        ba.insert(ba.end(), a.begin(), a.end());

        return ab > ba;
    });
    
    if (!nums.empty() && nums[0][0] == '0') {
        cout << "0" << endl;
        return 0;
    }
    
    for (const auto& row : nums) {
        for (char c : row) cout << c;
    }
    cout << "\n";

    return 0;
}