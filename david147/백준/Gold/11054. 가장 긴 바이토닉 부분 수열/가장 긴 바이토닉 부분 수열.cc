#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[1000], dp_inc[1000], dp_dec[1000];

void f() {
    
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        maximum = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                if (maximum < dp_inc[j]) maximum = dp_inc[j];
            }
        }
        dp_inc[i] = maximum + 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        maximum = 0;
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j]) {
                if (maximum < dp_dec[j]) maximum = dp_dec[j];
            }
        }
        dp_dec[i] = maximum + 1;
    }

    // for (int i = 0; i < n; i++) cout << dp_inc[i] << ' ';
    // cout << '\n';

    // for (int i = 0; i < n; i++) cout << dp_dec[i] << ' ';
    // cout << '\n';

    maximum = 0;
    for (int i = 0; i < n; i++) {
        if (maximum < dp_inc[i] + dp_dec[i]) maximum = dp_inc[i] + dp_dec[i];
    }

    cout << maximum - 1 << '\n';

    return 0;
}