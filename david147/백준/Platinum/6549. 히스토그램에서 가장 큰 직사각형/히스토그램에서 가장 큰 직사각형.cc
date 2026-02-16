#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans, idx;
bool flag;
long long arr[100001], seg_tree[400001];

void build(int start, int end, int index) {
    if (start == end) {
        seg_tree[index] = start;
        return;
    }

    int mid = (end + start) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);

    seg_tree[index] = arr[seg_tree[2 * index]] < arr[seg_tree[2 * index + 1]] ? seg_tree[2 * index] : seg_tree[2 * index + 1];
}

int find_idx(int start, int end, int index, int left, int right) {
    if (start > right || end < left) return -1;
    if (start >= left && end <= right) return seg_tree[index];

    int mid = (end + start) / 2, idx_left, idx_right;
    idx_left = find_idx(start, mid, 2 * index, left, right); 
    idx_right = find_idx(mid + 1, end, 2 * index + 1, left, right);
   
    if (idx_left == -1) return idx_right;
    else if (idx_right == -1) return idx_left;
    else return arr[idx_left] < arr[idx_right] ? idx_left : idx_right;
}

long long solve(int left, int right) {
    if (left > right) return 0;

    int idx;
    long long size_middle, size_left, size_right;

    idx = find_idx(1, n, 1, left, right);
    size_middle = (right - left + 1) * arr[idx];

    size_left = solve(left, idx - 1);
    size_right = solve(idx + 1, right);
    return max(max(size_middle, size_left), size_right);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        cin >> n;
        if (n == 0) break;

        for (int i = 1; i <= n; i++) cin >> arr[i];
        build(1, n, 1);
        cout << solve(1, n) << '\n';
    }
    return 0;
}