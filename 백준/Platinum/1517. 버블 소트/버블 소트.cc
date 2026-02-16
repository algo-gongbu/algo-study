#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)
#define N 500000

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
int seg_tree[2000001];
vector<int> arr, sorted_arr;

int query(int start, int end, int index, int left, int right) {
    if (start > right || end < left) return 0;
    if (start >= left && end <= right) return seg_tree[index];

    int mid = (start + end) / 2;
    return query(start, mid, 2 * index, left, right) + query(mid + 1, end, 2 * index + 1, left, right);
}

void update(int start, int end, int index, int target, int value) {
    if (target < start || target > end) return;
    if (start == end) {seg_tree[index] += value; return;}

    int mid = (start + end) / 2;
    update(start, mid, 2 * index, target, value);
    update(mid + 1, end, 2 * index + 1, target, value);
    
    seg_tree[index] = seg_tree[2 * index] + seg_tree[2 * index + 1];
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
        sorted_arr.push_back(temp);
    }

    sort(sorted_arr.begin(), sorted_arr.end());
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

    int rank;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        rank = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin();
        ans += query(0, N - 1, 1, rank + 1, N - 1);
        update(0, N - 1, 1, rank, 1);
    }

    cout << ans << '\n';

    return 0;
}