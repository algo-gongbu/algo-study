#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> visited;
vector<vector<int>> dan;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int dfs(int x, int y, int n){

    visited[x][y] = 1;
    int size = 1;

    for(int i =0; i < 4; i ++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(visited[nx][ny]) continue;
        if(dan[nx][ny] == 0) continue;

        size += dfs(nx,ny,n);
        
    }
    return size;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    cin >> n;
    dan.assign(n, vector<int>(n));
    visited.assign(n, vector<int>(n,0));
    vector<int> result;

    int count =0;
    // dan에 저장하기 
    for(int i =0; i < n; i++){
        string line;
        cin >> line;

        for(int j =0; j < n; j++){
            dan[i][j] = line[j] - '0';
            // cout << dan[i][j];
        }
    }


    for(int i =0; i < n; i++){
        for(int j =0; j<n; j++){
            if(dan[i][j] == 1 && !visited[i][j]){
                int x = dfs(i,j,n);
                result.push_back(x);
                count++;
            }
        }
    }
    cout << count << "\n";

    sort(result.begin(),result.end());

    for(int t : result){
        cout << t << "\n";
    }

}