#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int result = 0;

    for (int i=1; i<N; i++) {
        int sum = i;
        int temp = i;

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N) {
            result = i;
            break;
        }
    }

    cout << result << "\n";

    return 0;
}