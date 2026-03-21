#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1500
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[N][N], idx[N], num;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; ++i) idx[i] = n - 1;

    for (int i = 0; i < n; ++i) {
        maximum = INT_MIN;
        for (int j = 0; j < n; ++j) {
            if (maximum < arr[idx[j]][j]) {
                maximum = arr[idx[j]][j];
                num = j;
            }
        }
        --idx[num];
    }

    cout << maximum << '\n';

    return 0;
}