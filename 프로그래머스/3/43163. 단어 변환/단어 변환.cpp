#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> visited;
vector<vector<int>> graph;
queue<int> q;

bool compare(string s1, string s2){
    int n = s1.size();
    int diff = 0;
    
    for(int i =0; i< n;i++){
        if(s1[i] != s2[i]) diff++;
        
        if(diff > 1) return false;
    }
    return diff ==1;
}


void bfs(queue<int> &q){ // 필요한 시작점을 main 함수에서 넣어주기 

    while(!q.empty()){
        int cx = q.front();
        q.pop();
        
        for(int next : graph[cx]){
            if(!visited[next]){
                q.push(next);
                visited[next]  = visited[cx] + 1;
                
            }
        }
        
        
    }
    
    
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    auto it = std::find(words.begin(), words.end(), target);
    if(it == words.end()) return 0;
    int targetIdx = distance(words.begin() , it);
    
    int n = words.size();
    visited = vector<int> (n,0);
    graph = vector<vector<int>> (n); 
    // (n, vector<int> (n)) 초기화하면 vector에 0이 저장된 채로 시작함
    
    for(int i =0; i< n; i++){
        string main = words[i];
        
        for(int j =0; j< n; j++){
            if(i == j) continue;
            
            if(compare(main, words[j])) graph[i].push_back(j);
            
        }
    }
    // 단어가 하나 차이나는. 여러 시작점을 큐에 넣어주기 
    // 모든 지점에서의 최단거리를 구하기 위함.
    for(int i = 0; i < n ; i++){
        if(compare(begin, words[i]) || begin == words[i]) {
            visited[i] = 1;
            q.push(i);
        }
    }
    
    bfs(q);
    
    return visited[targetIdx];
    
    
}