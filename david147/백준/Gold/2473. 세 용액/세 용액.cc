#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 5e3

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
vector<long long> arr;

void f() {
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    long long temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    long long cur, s1, s2, s3, sum, mini = LONG_LONG_MAX;
    int left, right;
    for (int i = 0; i < n; i++) {
        cur = arr[i];

        left = 0, right = n - 1;
        while (left < right) {
            if (left == i) left++;
            if (right == i) right--;
            
            if (left >= right) break;

            sum = arr[left] + arr[right] + cur;
            if (mini > abs(sum)) {
                mini = abs(sum);
                s1 = cur, s2 = arr[left], s3 = arr[right];
            }

            if (sum > 0) right--;
            else if (sum < 0) left++;
            else break;
        }
    }

    cout << s1 << ' ' << s2 << ' ' << s3 << '\n';

    return 0;
}