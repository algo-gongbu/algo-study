#include <bits/stdc++.h>
using namespace std;

int n, ans;
bool diag1[30];
bool diag2[30];
bool col_used[15];

void solve(int row) {
    if (row == n) {
        ans++;
        return;
    }

    for (int col=0; col<n; col++) {
        int left_diag = row - col + n - 1;
        int right_diag = row + col;

        if (!col_used[col] && !diag1[left_diag] && !diag2[right_diag]) {
            col_used[col] = true;
            diag1[left_diag] = true;
            diag2[right_diag] = true;

            solve(row + 1);

            col_used[col] = false;
            diag1[left_diag] = false;
            diag2[right_diag] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    solve(0);
    cout << ans << '\n';

    return 0;
}

