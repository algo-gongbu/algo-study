#include <bits/stdc++.h>
using namespace std;

vector<int> visited;
vector<int> visited2;
vector<vector<int>> graph;
vector<int> result;
vector<int> result2;

void dfs(int x){
    visited[x] = 1;
    result.push_back(x);

    for(int next : graph[x]){
        if(!visited[next]){
            dfs(next);
            
        }
    }
}
void bfs(int x){
    queue<int> q;
    q.push(x);
    visited2[x] = 1;
    result2.push_back(x);

    while(!q.empty()){
        int cx = q.front();
        q.pop();

        for(int next : graph[cx]){
            if(!visited2[next]){
                q.push(next);
                visited2[next] = 1;
                result2.push_back(next);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,v;

    cin >> n >> m >> v;

    graph.assign(n+1, vector<int>());
    graph[0].push_back(0);

    // 양방향으로 그래프 구성
    for(int i =0; i < m ; i++){
        int a, b;

        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    for(int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end());
    }


    visited.assign(n + 1,0);
    visited2.assign(n + 1,0);

    dfs(v);
    bfs(v);

    for(int x : result){
        cout << x << " ";
    }
    cout << "\n";
    for(int y : result2){
        cout << y << " ";
    }

}