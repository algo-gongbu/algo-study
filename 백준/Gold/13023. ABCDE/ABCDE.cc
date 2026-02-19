#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
bool found = false;

void dfs(int x, int depth){

    if(found) return;

    if(depth == 4){
        found = true;
        return;
    }
    visited[x] = 1;

    for(int next : graph[x]){
        if(!visited[next]){
            dfs(next, depth + 1);
        }
    }
    visited[x] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;
    graph.assign(n+1, vector<int>());
    visited.assign(n,0);

    for(int i =0; i < m; i++){
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int count = 0;

    for(int i =0; i < n; i++){
        if(!visited[i]){
            dfs(i, 0);        
            if(found) break;
        }

    }

    if(found){
        cout << 1;
    }else{
        cout << 0;
    }


}