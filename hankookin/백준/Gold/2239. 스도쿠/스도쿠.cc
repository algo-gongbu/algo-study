#include <bits/stdc++.h>
using namespace std;

int board[9][9];
bool row_check[9][10];
bool col_check[9][10];
bool box_check[9][10];
vector<pair<int, int>> empty_cells;

int get_box(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

void print_board() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

bool solve(int idx) {
    if (idx == empty_cells.size()) {
        print_board();
        return true;
    }

    int r = empty_cells[idx].first;
    int c = empty_cells[idx].second;
    int b = get_box(r, c);

    for (int num = 1; num <= 9; num++) {
        if (!row_check[r][num] && !col_check[c][num] && !box_check[b][num]) {
            board[r][c] = num;
            row_check[r][num] = col_check[c][num] = box_check[b][num] = true;

            if (solve(idx + 1)) return true;

            board[r][c] = 0;
            row_check[r][num] = col_check[c][num] = box_check[b][num] = false;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 9; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 9; j++) {
            int val = line[j] - '0'; 
            board[i][j] = val;
            if (val != 0) {
                row_check[i][val] = true;
                col_check[j][val] = true;
                box_check[get_box(i, j)][val] = true;
            } else {
                empty_cells.push_back({i, j});
            }
        }
    }

    solve(0);

    return 0;
}