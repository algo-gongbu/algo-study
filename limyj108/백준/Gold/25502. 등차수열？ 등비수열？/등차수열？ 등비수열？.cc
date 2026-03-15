#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, i;
    long long x;
    cin >> N >> M;

    unordered_map<long long, int> diff;
    vector<long long> v(N);

    for (int n = 0; n < N; n++) {
        cin >> v[n];
        if (n > 0) {
            diff[v[n] - v[n - 1]] += 1;
        }
    }

    while (M--) {
        bool arith = false, geo = false;
        cin >> i >> x;
        i--;
        if (i > 0) { // i - 1번째 항과 i번째 항
            diff[v[i] - v[i - 1]]--;
            diff[x - v[i - 1]]++;
        }
        if (i < N - 1) { // i번째 항과 i + 1번째 항
            diff[v[i + 1] - v[i]]--;
            diff[v[i + 1] - x]++;
        }
        v[i] = x;

        if (i > 0) {
            if (v[i] - v[i - 1] > 0 && (diff[v[i] - v[i - 1]] == N - 1)) {
                arith = true;
            }
        }
        else {
            if (v[i + 1] - v[i] > 0 && (diff[v[i + 1] - v[i]] == N - 1)) {
                arith = true;
            }
        }

        if (diff[0] == N - 1) { // 공비가 1인 등비수열
            geo = true;
        }
        else if (N < 60 && (v[1] % v[0] == 0)) {
            /*
                2 ^ 10 > 10 ^ 3 -> 2 ^ 60 > 10 ^ 18
                공비가 1보다 크면, 등비수열의 길이가 60 이상일 수 없음.
            */
            geo = true;
            long long r = v[1] / v[0];
            for (int n = 1; n < N - 1; n++) {
                if (!((v[n + 1] %  v[n] == 0) && (v[n + 1] / v[n] == r))) {
                    geo = false;
                }
            }
        }

        if (arith) {
            cout << "+\n";
        }
        else if (geo) {
            cout << "*\n";
        }
        else {
            cout << "?\n";
        }
    }

    return 0;
}