#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<long long>> v(3, vector<long long>(n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    long long prev = -1;
    for (int i = 0; i < n; i++) {
        vector<long long> temp = { v[0][i], v[1][i], v[2][i] };
        sort(temp.begin(), temp.end());
        if (prev + 1 < temp[1]) {
            prev = max(temp[0], prev + 1);
        }
        else if (prev + 1 > temp[1]) {
            if (prev + 1 > temp[2]) {
                cout << "NO\n";
                return 0;
            }
            else {
                prev = min(prev + 1, temp[2]);
            }
        }
        else {
            prev += 1;
        }
    }
    cout << "YES\n";
    return 0;
}