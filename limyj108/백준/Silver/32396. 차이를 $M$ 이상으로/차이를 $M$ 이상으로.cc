#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N, ans = 0;
    long long M, prev, cur;
    bool flag = false;

    cin >> N >> M;
    cin >> prev;

    for (int i = 1; i < N; i++) {
        cin >> cur;
        if (flag) {
            flag = false;
        }
        else if (abs(cur - prev) < M) {
            ans++;
            flag = true;
        }
        prev = cur;
    }
    cout << ans;

    return 0;
}