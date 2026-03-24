#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1e6
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int dupl[1001];
vector<int> arr, s_arr;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    while (n--) {
        cin >> m;
        arr.push_back(m);
        s_arr.push_back(m);
    }
    sort(s_arr.begin(), s_arr.end());

    for (const int& elt : arr) {
        auto pos = lower_bound(s_arr.begin(), s_arr.end(), elt);
        cout << pos - s_arr.begin() + dupl[elt] << ' ';
        ++dupl[elt];
    }
    cout << '\n';

    return 0;
}