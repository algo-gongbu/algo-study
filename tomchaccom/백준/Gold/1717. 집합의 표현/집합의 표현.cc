#include <iostream>
#include <vector>
using namespace std;

vector<int> graph;


int find(int x){
    if(graph[x] < 0){
        return x;
    }else{
        return graph[x] = find(graph[x]); 
    }

}

bool uni(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v){ // 루트가 똑같을 때는 아무거나 밑에 넣음
        return false;
    }

    if(graph[v] < graph[u]){
        swap(u,v); // graph[u] 가 더 트리의 높이가 높다. 
    }
     // 트리의 높이를 비교해야함. 그래서 비교시 낮은 높이를 선택하기

    if(graph[v] == graph[u]){ // 높이가 같다면 U 에 넣자. 
        graph[u]--;
    }
    graph[v] = u; // 트리의 높이가 다르다면 트리의 높이가 더 높은 쪽이 루트가 된다
    return true;
    
}


int main(){

    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n,m; 
    cin >> n >> m;

    graph = vector<int> (n+1, -1);

    for(int i = 0; i < m; i++){
        int command, a, b;

        cin >> command >> a >> b;

        if(command == 0){
            uni(a,b);
        }else{
            if( find(a) == find(b)){
                cout<< "yes" << "\n";
            }else{
                cout << "no" << "\n";
            }
        }


    }
}