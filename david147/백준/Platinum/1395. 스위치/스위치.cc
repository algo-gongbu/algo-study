#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int arr[100001], seg_tree[400001], lazy[400001];

void force(int start, int end, int index) {
    if (lazy[index] & 1) {
        seg_tree[index] = (end - start + 1) - seg_tree[index];

        if (start < end) {
            lazy[2 * index] += lazy[index];
            lazy[2 * index + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
}

void update(int start, int end, int index, int left, int right) {
    force(start, end, index);
    if (start > right || end < left) return;
    if (start >= left && end <= right) {
        lazy[index] += 1;
        force(start, end, index);
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, 2 * index, left, right);
    update(mid + 1, end, 2 * index + 1, left, right);

    seg_tree[index] = seg_tree[2 * index] + seg_tree[2 * index + 1];
}

int query(int start, int end, int index, int left, int right) {
    force(start, end, index);
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return seg_tree[index];

    int mid = (start + end) / 2;
    return query(start, mid, 2 * index, left, right) + query(mid + 1, end, 2 * index + 1, left, right);
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        if (a == 0) update(1, n, 1, b, c);
        if (a == 1) cout << query(1, n, 1, b, c) << '\n';
    }

    return 0;
}