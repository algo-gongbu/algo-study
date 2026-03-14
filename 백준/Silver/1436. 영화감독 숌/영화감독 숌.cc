#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int output = 666;
    int count = 1;

    while (1) {
        if (to_string(output).find("666") != string::npos) {
            if (count == N) {
                cout << output << "\n";
                break;
            }
            else count++;
        }
        output++;
    }

    return 0;
}