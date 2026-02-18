#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
int arr[10000];
bool flag;

void preToPost(int start, int end) {
    if (start > end) return;

    int temp = arr[start], i = start + 1;
    while (i <= end) {
        if (temp < arr[i]) {temp = arr[i]; break;}
        else i++;
    }

    preToPost(start + 1, i - 1);
    preToPost(i, end);

    cout << arr[start] << '\n';
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int index = -1;
    while (cin >> n) arr[++index] = n;
    preToPost(0, index);

    return 0;
}