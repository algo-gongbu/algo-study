#include <bits/stdc++.h>
using namespace std;


void dfs(int x, vector<vector<int>>& graph, vector<int>& visited){
    visited[x] = 1;

    for(int next : graph[x]){
        if(!visited[next]){
            dfs(next , graph, visited);
        }
    }
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1, 0);

    for(int i =0; i < m; i++){
        int a, b;

        cin >> a >>b;

        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    int count =0;

    for(int j =1; j <=n; j++){
        if(!visited[j]){
            dfs(j, graph, visited);
            count++;
        }
    }
    cout << count;


}

