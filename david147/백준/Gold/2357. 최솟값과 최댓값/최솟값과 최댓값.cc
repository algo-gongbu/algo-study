#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
long long int arr[1000001], seg_tree_max[4000001], seg_tree_min[4000001];

void build(int start, int end, int index) {
    if (start == end) {
        seg_tree_max[index] = arr[start];
        seg_tree_min[index] = arr[start]; 
        return;
    }

    int mid = (end + start) / 2;
    build(start, mid, 2 * index);
    build(mid + 1, end, 2 * index + 1);

    seg_tree_max[index] = max(seg_tree_max[2 * index], seg_tree_max[2 * index + 1]);
    seg_tree_min[index] = min(seg_tree_min[2 * index], seg_tree_min[2 * index + 1]);
}

void find(int start, int end, int index, int left, int right) {
    if (start > right || end < left) return;

    if (left <= start && end <= right) {
        if (maximum < seg_tree_max[index]) maximum = seg_tree_max[index];
        if (minimum > seg_tree_min[index]) minimum = seg_tree_min[index];
        return;
    }

    int mid = (end + start) / 2;
    find(start, mid, 2 * index, left, right);
    find(mid + 1, end, 2 * index + 1, left, right);
}


int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    build(1, n, 1);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        maximum = INT_MIN, minimum = INT_MAX;
        find(1, n, 1, a, b);
        cout << minimum << ' ' << maximum << '\n';
    }

    return 0;
}