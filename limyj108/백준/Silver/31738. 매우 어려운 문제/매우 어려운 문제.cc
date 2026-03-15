#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N, ans = 1;
    int M;
    cin >> N >> M;

    if (N >= M) {
        cout << 0;
        return 0;
    }

    for (long long i = 2; i <= N; i++) {
        ans = (ans * i) % M;
    }
    cout << ans;

    return 0;
}