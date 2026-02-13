#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
string arr[3072];

void f(int row, int index) {
    if (index == 1) {
        arr[row] += "  *   ";
        arr[row + 1] += " * *  ";
        arr[row + 2] += "***** ";
    }
    else {
        for (int i = 0; i < (index >> 1) * 3; i++) {
            arr[row + i] += string((index >> 1) * 3, ' ');
        }

        f(row, index >> 1);
        f(row + index * 3 / 2, index >> 1);

        for (int i = 0; i < (index >> 1) * 3; i++) {
            arr[row + i] += string((index >> 1) * 3, ' ');
        }
        f(row + index * 3 / 2, index >> 1);
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    f(0, n / 3);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << '\n';
    }

    return 0;
}