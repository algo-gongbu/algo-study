#include <string>
#include <iostream>
#include <vector>
#define DIV 1000000007

using namespace std;

bool is_puddles(int r, int c, vector<vector<int>>& puddles);

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> D(n + 1, vector<int>(m + 1, 0));

    for (int r = 1; r <= n; r++) {
        if (is_puddles(r, 1, puddles))
            break;
        D[r][1] = 1;
    }
    for (int c = 1; c <= m; c++) {
        if (is_puddles(1, c, puddles))
            break;
        D[1][c] = 1;
    }
    
    for (int r = 2; r <= n; r++) {
        for (int c = 2; c <= m; c++) {
            if (is_puddles(r, c, puddles)) {
                continue;      
            }
            D[r][c] = ((D[r - 1][c] + D[r][c - 1]) % DIV);
        }
    }
    
    return D[n][m];
}

bool is_puddles(int r, int c, vector<vector<int>>& puddles) {
    int R = puddles.size();
    for (int i = 0; i < R; i++) {
        if (c == puddles[i][0] && r == puddles[i][1]) {
            return true;
        }
    }
    return false;
}