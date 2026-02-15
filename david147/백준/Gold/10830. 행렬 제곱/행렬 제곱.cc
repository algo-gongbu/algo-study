#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, h, maximum = INT_MIN, minimum = INT_MAX, ans;
long int m;
bool flag;
int matrix[5][5], res[5][5];

void f(long int exp) {
    if (exp == 1) return;
    else {
        bool flag = false;
        if (exp & 1) flag = true;

        f(exp >> 1);
        int temp1[5][5] = { 0 };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    temp1[i][j] += ((res[i][k] * res[k][j]) % 1000);
                    temp1[i][j] %= 1000;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = temp1[i][j];
            }
        }

        if (flag) {
            int temp2[5][5] = { 0 };
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        temp2[i][j] += ((res[i][k] * matrix[k][j]) % 1000);
                        temp2[i][j] %= 1000;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    res[i][j] = temp2[i][j];
                }
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> temp;
            temp %= 1000;
            res[i][j] = matrix[i][j] = temp % 1000;
        }
    }

    f(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}