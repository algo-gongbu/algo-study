#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 1500
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        priority_queue<int> max_pq;
        priority_queue<int, vector<int>, greater<int>> min_pq;
        
        cin >> m;
        cout << m / 2 + 1 << '\n';

        cin >> h;
        max_pq.push(h);
        cout << h << ' ';

        for (int i = 1; i < m; ++i) {
            cin >> h;

            if (i % 20 == 0) cout << '\n';

            if (h <= max_pq.top()) max_pq.push(h);
            else min_pq.push(h);
            
            if (i % 2 == 0) {
                while (max_pq.size() != min_pq.size() + 1) {
                    if (max_pq.size() > min_pq.size() + 1) {
                        min_pq.push(max_pq.top());
                        max_pq.pop();
                    }
                    else {
                        max_pq.push(min_pq.top());
                        min_pq.pop();
                    }
                }
                
                cout << max_pq.top() << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}