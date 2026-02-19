#include <bits/stdc++.h>
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
int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;
    
    graph.resize(n+1); // 줄이면 뒤에서 부터 잘림, 늘리면 뒤에 기본값을 추가 
    visited.assign(n+1, 0); // assign은 크기를 할당할 때 기존의 내용을 삭제하고, value 할당

    for(int i =0; i < m; i++){
        int a, b;

        cin >> a >>b;

        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    int count =0;

    for(int j =1; j <=n; j++){
        if(!visited[j]){
            dfs(j);
            count++;
        }
    }
    cout << count;


}

