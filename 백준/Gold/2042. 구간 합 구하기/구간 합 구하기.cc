#include <bits/stdc++.h>
using namespace std;

long long init(vector<long long>& arr, vector<long long>& tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }
    int mid = (start + end) / 2;
    return tree[node] = init(arr, tree, node * 2, start, mid) + 
                        init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update(vector<long long>& tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;
    
    tree[node] += diff;
    
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

long long query(vector<long long>& tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    
    if (left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    return query(tree, node * 2, start, mid, left, right) + 
           query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    if (!(cin >> N >> M >> K)) return 0;

    vector<long long> arr(N + 1);
    vector<long long> tree(N * 4);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(arr, tree, 1, 1, N);

    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            long long diff = c - arr[b];
            arr[b] = c; 
            update(tree, 1, 1, N, b, diff);
        } else if (a == 2) { 
            cout << query(tree, 1, 1, N, b, c) << "\n";
        }
    }

    return 0;
}

