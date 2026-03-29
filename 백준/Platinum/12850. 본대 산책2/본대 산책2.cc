#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

const ll mod = 1000000007;

matrix adj = {{0, 1, 1, 0, 0, 0, 0, 0},  // 정보과학관
              {1, 0, 1, 1, 0, 0, 0, 0},  // 전산관
              {1, 1, 0, 1, 1, 0, 0, 0},  // 미래관
              {0, 1, 1, 0, 1, 1, 0, 0},  // 신양관
              {0, 0, 1, 1, 0, 1, 1, 0},  // 한경직기념관
              {0, 0, 0, 1, 1, 0, 0, 1},  // 진리관
              {0, 0, 0, 0, 1, 0, 0, 1},  // 형남공학관
              {0, 0, 0, 0, 0, 1, 1, 0}}; // 학생회관



matrix multiply(matrix a, matrix b) {
    matrix res(8, vector<ll>(8, 0));

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 8; ++k) {
                res[i][j] += (a[i][k] * b[k][j]) % mod;
                res[i][j] %= mod;
            }
        }
    }

    return res;
}

matrix power(matrix a, int exp) {
    matrix res(8, vector<ll>(8, 0));
    for (int i = 0; i < 8; ++i) res[i][i] = 1;

    while (exp) {
        if (exp % 2) res = multiply(res, a);
        a = multiply(a, a);
        exp /= 2;
    }

    return res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int d;
    cin >> d;
    matrix res = power(adj, d);

    // (i, j)-th component of the n-th power of the adjacency matrix: 
    //  the number of cases starting at the i-th node and ending at the j-th node after n (time units)
    cout << res[0][0] << '\n';

    return 0;
}