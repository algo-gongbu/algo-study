#include <iostream>
#include <vector>

using namespace std;

int N, S;
int arr[20];
int cnt = 0;

void solve(int idx, int current_sum) {
    if (idx == N) {
        if (current_sum == S) {
            cnt++;
        }
        return;
    }
    
    solve(idx + 1, current_sum + arr[idx]);
    solve(idx + 1, current_sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    solve(0, 0);
    
    if (S == 0) {
        cnt--;
    }

    cout << cnt << "\n";

    return 0;
}