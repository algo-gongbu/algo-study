#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> cabbage;
vector<vector<int>> visited;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int x, int y, int n, int m){

    visited[x][y] = 1;

    for(int i =0; i< 4; i++){

        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue; 
        if(visited[nx][ny]) continue;
        if(cabbage[nx][ny] == 0) continue;

        dfs(nx,ny,n,m);
    }
    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test; 
    int m ,n ,k;

    cin >> test;

    for(int i =0; i < test; i++){
        int count = 0;

        cin >> n >> m >> k;

        cabbage.assign(n, vector<int>(m,0));
        visited.assign(n, vector<int>(m,0));

        for(int j =0; j< k; j++){
            int x,y;

            cin >> x >> y;
            cabbage[x][y] = 1;

        }

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(cabbage[r][c] == 1 && visited[r][c] == 0){
                    count++; 
                    dfs(r,c,n,m);
                }
            }
        }
        cout << count << "\n";

    }

}