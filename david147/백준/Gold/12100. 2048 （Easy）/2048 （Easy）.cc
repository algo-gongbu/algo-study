#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using matrix = vector<vector<ll>>;

#define all(v) v.begin(), v.end()

int n;
ll maximum = 0;
void f(matrix cur_board, int cnt) {
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maximum = max(maximum, cur_board[i][j]);
        }
    }

    if (cnt == 5) return;
    
    matrix nxt_board;
    nxt_board.assign(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        int idx = 0;
        for (int j = 0; j < n; ++j) {
            if (!cur_board[i][j]) continue;

            if (!nxt_board[i][idx]) nxt_board[i][idx] = cur_board[i][j];
            else {
                if (nxt_board[i][idx] == cur_board[i][j]) nxt_board[i][idx++] <<= 1;
                else nxt_board[i][++idx] = cur_board[i][j];
            }
        }
    }
    if (nxt_board != cur_board) f(nxt_board, cnt + 1);

    nxt_board.assign(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        int idx = 0;
        for (int j = 0; j < n; ++j) {
            if (!cur_board[j][i]) continue;

            if (!nxt_board[idx][i]) nxt_board[idx][i] = cur_board[j][i];
            else {
                if (nxt_board[idx][i] == cur_board[j][i]) nxt_board[idx++][i] <<= 1;
                else nxt_board[++idx][i] = cur_board[j][i];
            }
        }
    }
    if (nxt_board != cur_board) f(nxt_board, cnt + 1);

    nxt_board.assign(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        int idx = n - 1;
        for (int j = n - 1; j >= 0; --j) {
            if (!cur_board[i][j]) continue;

            if (!nxt_board[i][idx]) nxt_board[i][idx] = cur_board[i][j];
            else {
                if (nxt_board[i][idx] == cur_board[i][j]) nxt_board[i][idx--] <<= 1;
                else nxt_board[i][--idx] = cur_board[i][j];
            }
        }
    }
    if (nxt_board != cur_board) f(nxt_board, cnt + 1);

    nxt_board.assign(n, vector<ll>(n, 0));
    for (int i = 0; i < n; ++i) {
        int idx = n - 1;
        for (int j = n - 1; j >= 0; --j) {
            if (!cur_board[j][i]) continue;

            if (!nxt_board[idx][i]) nxt_board[idx][i] = cur_board[j][i];
            else {
                if (nxt_board[idx][i] == cur_board[j][i]) nxt_board[idx--][i] <<= 1;
                else nxt_board[--idx][i] = cur_board[j][i];
            }
        }
    }
    if (nxt_board != cur_board) f(nxt_board, cnt + 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    matrix board(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> board[i][j];
        }
    }

    f(board, 0);

    cout << maximum << '\n';

    return 0;
}