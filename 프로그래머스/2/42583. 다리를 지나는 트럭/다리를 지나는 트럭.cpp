#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current = 0;
    queue<int> q;
    
    for(int i =0; i < bridge_length; i++){ 
        q.push(0);
    }
    
    while(!truck_weights.empty()){
        answer++;
        
        current -= q.front(); // 현재 다리 무게에서 나가는 트럭의 무게를 제거
        q.pop();
        
        if(current + truck_weights.front() <= weight){
            q.push(truck_weights.front());
            current += truck_weights.front();
            truck_weights.erase(truck_weights.begin()); 
            
        }else{
            q.push(0);
        }
    }
    
    
    return answer + bridge_length;
}