#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool people[51], flag;
int party[51][51];

void f() {
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int cnt, temp;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        cin >> temp;
        people[temp] = true;
    }

    for (int i = 0; i < m; i++) {
        flag = false;

        cin >> party[i][0];
        for (int j = 0; j < party[i][0]; j++) {
            cin >> temp;
            if (!flag && people[temp]) flag = true;
            party[i][j + 1] = temp;
        }

        if (flag) {
            for (int j = 0; j < party[i][0]; j++) {
                people[party[i][j + 1]] = true;
            }
        }
    }

    for (int x = 0; x < m; x++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < party[i][0]; j++) {
                if (people[party[i][j + 1]]) {
                    for (int k = 0; k < party[i][0]; k++) {
                        people[party[i][k + 1]] = true;
                    }
                    break;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        flag = false;
        for (int j = 0; j < party[i][0]; j++) {
            if (people[party[i][j + 1]]) {
                flag = true;
                break;
            }
        }
        if (!flag) ans++;
    }

    cout << ans << '\n';

    return 0;
}