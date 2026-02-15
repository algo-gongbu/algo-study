#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long int arr[1000001], seg_tree[4000001];

void build(int start, int end, int index) {
    if (start == end) {seg_tree[index] = arr[start]; return;}

    int mid = (end + start) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);

    seg_tree[index] = seg_tree[2 * index] + seg_tree[2 * index + 1];
}

void update(int start, int end, int index, int target, long long int value) {
    if (target < start || target > end) return;
    if (start == end) {seg_tree[index] = value; return;}

    int mid = (end + start) / 2;
    update(start, mid, 2 * index, target, value);
    update(mid + 1, end, 2 * index + 1, target, value);

    seg_tree[index] = seg_tree[2 * index] + seg_tree[2 * index + 1];
}

long long int interval_sum(int start, int end, int index, int left, int right) {
    if (start > right || end < left) return 0;
    if (left <= start && end <= right) return seg_tree[index];

    int mid = (end + start) / 2;
    return interval_sum(start, mid, 2 * index, left, right) + interval_sum(mid + 1, end, 2 * index + 1, left, right);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, n, 1);

    int a, b;
    long long int c;
    for (int i = 0; i < m + h; i++) {
        cin >> a >> b >> c;

        if (a == 1) update(1, n, 1, b, c);
        else if (a == 2) cout << interval_sum(1, n, 1, b, c) << '\n';
    }

    return 0;
}