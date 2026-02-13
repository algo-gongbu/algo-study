#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int n, m, h, maximum = INT_MIN, minimum = INT_MAX;
int house[200], chicken[26], res[100];
int dist[13][100];
int temp, index_h, index_c;

void f(int index, int cnt)
{
    if (cnt == 1) {
        temp = 0;
        for (int i = 0; i < index_h >> 1; i++) temp += res[i];
        if (temp < minimum) minimum = temp;
    }
    else {
        int arr[100] = {0};
        for (int i = index + 1; i < index_c >> 1; i++) {
            for (int x = 0; x < index_h >> 1; x++) arr[x] = res[x];
            for (int j = 0; j < index_h >> 1; j++) {
                if (res[j] > dist[i][j]) res[j] = dist[i][j];
            }
            f(i, cnt - 1);
            for (int x = 0; x < index_h >> 1; x++) res[x] = arr[x];
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> temp;
            if (temp == 1) {
                house[index_h++] = j;
                house[index_h++] = i;
            }
            if (temp == 2) {
                chicken[index_c++] = j;
                chicken[index_c++] = i;
            }
        }
    }

    int x_c, y_c;
    for (int i = 0; i < index_c >> 1; i++) {
        x_c = chicken[i << 1];
        y_c = chicken[(i << 1) + 1];

        for (int j = 0; j < index_h >> 1; j++) {
            dist[i][j] = abs(x_c - house[j << 1]) + abs(y_c - house[(j << 1) + 1]);
        }
    }

    for (int i = 0; i < index_c >> 1; i++) {
        for (int j = 0; j < index_h >> 1; j++) { res[j] = dist[i][j]; }
        f(i, m);
    }

    cout << minimum << '\n';

    return 0;
}