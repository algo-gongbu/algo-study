#include <bits/stdc++.h>
using namespace std;

int N;
int max_val = 0;

void move_up(vector<vector<int>>& b) {
    for (int j = 0; j < N; ++j) {
        int target_row = 0; 
        int last_val = 0;   
        
        for (int i = 0; i < N; ++i) {
            if (b[i][j] == 0) continue; 
            
            if (last_val == 0) {
                last_val = b[i][j];
            } else if (last_val == b[i][j]) {
                b[target_row++][j] = last_val * 2;
                last_val = 0; 
            } else {
                b[target_row++][j] = last_val;
                last_val = b[i][j];
            }
        }
  
        if (last_val != 0) {
            b[target_row++][j] = last_val;
        }
   
        while (target_row < N) {
            b[target_row++][j] = 0;
        }
    }
}

void rotate(vector<vector<int>>& b) {
    vector<vector<int>> temp = b;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            b[i][j] = temp[N - 1 - j][i];
        }
    }
}

void dfs(int depth, vector<vector<int>> b) {
    if (depth == 5) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                max_val = max(max_val, b[i][j]);
            }
        }
        return;
    }

    for (int i = 0; i < 4; ++i) {
        vector<vector<int>> next_b = b;
        
        move_up(next_b);        
        dfs(depth + 1, next_b);   
        rotate(b);                
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    if (!(cin >> N)) return 0;
    
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    
    dfs(0, board);
    
    cout << max_val << "\n";
    return 0;
}

