#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tomato;
queue<pair<int,int>> q;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){

    ios ::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,n;

    cin >> m >> n;

    tomato.assign(n, vector<int>(m));


    for(int r = 0; r < n; r++){
        for(int c =0; c < m; c++){
            int value;
            cin >> value;
            tomato[r][c] = value;

            if (value == 1){
                q.push({r,c});
            }
        }
    }
    
    while(!q.empty()){
        auto [cx,cy] = q.front();
        q.pop();

        for(int i =0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
            if(tomato[nx][ny] != 0) continue;

            q.push({nx,ny});
            tomato[nx][ny] = tomato[cx][cy] + 1;

        }
    }
    int mx = -1;

    for(int r = 0; r < n; r++){
        for(int c =0; c < m; c++){
            if(tomato[r][c] == 0){
                cout << -1;
                return 0;
            }
            mx = max(mx, tomato[r][c]);
        }
    }
    cout << mx -1;

}