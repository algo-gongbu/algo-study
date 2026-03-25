#include <string>
#include <vector>

using namespace std;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int x){
    
    visited[x] = 1;
    
    for(int next : graph[x]){
        if(!visited[next]){
            dfs(next);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    graph = vector<vector<int>> (n);
    visited = vector<int>(n,0);
    
    for(int i = 0; i < n; i++){
        for(int j =0; j< n; j++){
            if(i == j) continue;
            
            if(computers[i][j]){
                graph[i].push_back(j);
                graph[j].push_back(i);
                
            }
            
            
        }
        
    }
    for(int j =0; j< n; j++){
        if(!visited[j]){
            dfs(j);
            answer++;
        }
    }
    
    
    return answer;
}