#include <string>
#include <vector>
#include <set>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
vector<vector<int>> group;
vector<int> groupSize;

int dfs(int x, int y, vector<vector<int>>& land, 
        int n , int m, int groupId){
    
    int count = 1;
    group[x][y] = groupId;
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx < 0 || nx >=n || ny <0 || ny>= m) continue;
        if(group[nx][ny]) continue; // 0일때 
        if(land[nx][ny] == 0) continue;
        
        count += dfs(nx,ny,land,n,m,groupId);
    }
    return count;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    
    int row = land.size();
    int col = land[0].size();
    
    group.assign(row,vector<int>(col,0));
    groupSize.push_back(0);
    
    int groupId = 0;
    
    for(int i = 0; i < row; i ++){
        for(int j = 0; j < col; j++){
            if(land[i][j] == 1 && group[i][j] == 0){
                groupId++;
                int size = dfs(i,j,land,row,col,groupId);
                groupSize.push_back(size);
                
            }
        }
    }
    for(int c =0 ; c < col; c++){
        
        set<int> used;
        int sum = 0;
        
        for(int r = 0; r < row; r++){
            int gid = group[r][c];
            
            if(gid != 0 &&used.find(gid) == used.end()){
                used.insert(gid);
                sum += groupSize[gid];
            }
            
        }
        answer = max(sum, answer);
        
    }
    
    
    return answer;
}




