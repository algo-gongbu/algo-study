#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long coordinate[10000][2];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> coordinate[i][0] >> coordinate[i][1];

    long long sum1 = 0, sum2 = 0;
    for (int i = 0; i < n - 1; i++) {
        sum1 += coordinate[i][0] * coordinate[i + 1][1];
        sum2 += coordinate[i][1] * coordinate[i + 1][0];
    }
    sum1 += coordinate[n - 1][0] * coordinate[0][1];
    sum2 += coordinate[n - 1][1] * coordinate[0][0];
    double res = (sum1 - sum2) / (double) 2;
    if (res < 0) res = -res;

    printf("%.1lf\n", res);

    return 0;
}