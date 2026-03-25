#include<vector>
#include<queue>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

vector<vector<int>> visited;

void bfs(int x, int y, int n, int m, vector<vector<int>>& maps){
    visited[x][y] = 1;
    
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        auto [cx,cy] = q.front();
        q.pop();
        
        
        for(int i = 0; i < 4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
            if(!maps[nx][ny]) continue;
            if(visited[nx][ny]) continue;
            
            q.push({nx,ny});
            visited[nx][ny] = visited[cx][cy] + 1;
            
        }
        
    }
   
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    int n = maps.size();
    int m= maps[0].size();
    visited = vector<vector<int>> (n, vector<int>(m,0));
    
    bfs(0,0,n,m,maps);
    
    if(visited[n-1][m-1] == 0){
        return -1;
    }else{
        return visited[n-1][m-1];
    }
    
}