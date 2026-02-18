#include "bits/stdc++.h"
using namespace std;

int n;
vector<pair<int,int>> black;
vector<pair<int,int>> white;
bool diag1[20];
bool diag2[20];
int max_black = 0;
int max_white = 0;

void solve(int idx, int count, const vector<pair<int,int>>& board, int& max_val) {
    if (idx == board.size()) {
        max_val = max(max_val, count);
        return;
    }

    int r = board[idx].first;
    int c = board[idx].second;
    int d1 = r-c+n-1;
    int d2 = r+c;

    if (!diag1[d1] && !diag2[d2]) {
        diag1[d1] = true;
        diag2[d2] = true;

        solve(idx+1, count+1, board, max_val);

        diag1[d1] = false;
        diag2[d2] = false;
    }
    solve(idx+1, count, board, max_val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            int piece;
            cin >> piece;
            if (piece == 1) {
                if ((i+j)%2==0) black.push_back({i,j});
                else white.push_back({i,j});
            }
        }
    }
    solve(0,0,black,max_black);
    solve(0,0,white,max_white);
    cout << max_black + max_white << "\n";
    
    return 0;
}