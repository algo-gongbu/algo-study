#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    if (N == 1) {
        cout << "YES\n1";
    }
    else if (N == 2) {
        cout << "NO";
    }
    else {
        cout << "YES\n" << "1 3 2";
        for (int i = 4; i <= N; i++) {
            cout << " " << i;
        }
    }

    return 0;
}