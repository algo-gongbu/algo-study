#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

vector<bool> is_prime(10000, true);
vector<int> prime;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 2; i < 10000; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = i + i; j < 10000; j += i) is_prime[j] = false;        
        }
    }

    int n;
    cin >> n;

    queue<int> p;
    p.push(2); p.push(3); p.push(5); p.push(7);
    for (int i = 2; i <= n; ++i) {
        int cur_size = p.size();
        for (int j = 0; j < cur_size; ++j) {
            int val = p.front();
            p.pop();

            for (int k = 1; k < 10; ++k) {
                int cur = val * 10 + k;
                if (cur < 10000) {
                    if (is_prime[cur]) p.push(cur);
                }
                else {
                    bool flag = true;
                    for (const int& d : prime) {
                        if (d * d > cur) break;
                        if (cur % d == 0) {flag = false; break;}
                    }
                    if (flag) p.push(cur);
                }
            }
        }
    }

    while (!p.empty()) {
        cout << p.front() << '\n';
        p.pop();
    }

    return 0;
}