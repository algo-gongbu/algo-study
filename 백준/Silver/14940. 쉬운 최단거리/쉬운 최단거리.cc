#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                q.push({i,j});
                dist[i][j] = 0;
            }
            else if (map[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx>=0 && nx<n && ny>=0 && ny<m) {
                if (map[nx][ny] == 1 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}