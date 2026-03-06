#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // 인덱스를 같이 큐에 넣어야 함. 
    // 실제로 location 이랑 == 인덱스 일때 종료되고 그때의 시행을 리턴
    
    int idx = priorities.size() - 1;
    
    queue<pair<int,int>> q;
    for(int i = 0; i < priorities.size(); i++){
        q.push({priorities[i], i});
    }
    
    sort(priorities.begin(), priorities.end());
    
    while(!q.empty()){
        
        auto [pro, index] = q.front();
        
        if(pro != priorities[idx]){
            q.pop();
            q.push({pro,index});
        }else{
            q.pop();
            idx--;
            answer++;
            if(index == location){
                break;
            }
        }
    }
    
    return answer;
}