#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e5
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[15][15];

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

    set<int> s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l <= k; ++l) {
                    for (int y = j; y <= i; ++y) {
                        for (int x = l; x <= k; ++x) {
                            s.insert(arr[y][x]);
                        }
                    }
                    if (s.size() == (i - j + 1) * (k - l + 1) 
                        && *(s.begin()) == 1 && *(--s.end()) == (i - j + 1) * (k - l + 1)) ++ans;

                    s.clear();
                }
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}