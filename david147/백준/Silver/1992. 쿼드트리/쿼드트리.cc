#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e5
#define mod (long long) 1e9

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
char image[64][64];

string f(int y, int x, int size) {
    if (size == 0) return string{image[y][x]};

    string s1 = f(y, x, size / 2);
    string s2 = f(y, x + size / 2, size / 2);
    string s3 = f(y + size / 2, x, size / 2);
    string s4 = f(y + size / 2, x + size / 2, size / 2);

    if (s1.size() == 1 && s2.size() == 1 && s3.size() == 1 && s4.size() == 1 
        && s1 == s2 && s1 == s3 && s1 == s4) return s1;
    else return '(' + s1 + s2 + s3 + s4 + ')';
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> image[i][j];
        }
    }

    cout << f(0, 0, n) << '\n';
    
    return 0;
}