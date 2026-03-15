#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[100000];

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    int left = 0, right = n - 1, temp, s1, s2;
    while (left < right) {
        temp = arr[left] + arr[right];
        if (abs(temp) < minimum) {
            minimum = abs(temp);
            s1 = left, s2 = right;
        }

        if (temp > 0) right--;
        else if (temp < 0) left++;
        else break;
    }

    cout << arr[s1] << ' ' << arr[s2] << '\n';

    return 0;
}