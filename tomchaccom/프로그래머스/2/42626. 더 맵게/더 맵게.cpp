#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 리스트에서 스코빌 지수가 낮은거 일단 가지고 와야함. 
    priority_queue<int, vector<int>, greater<int>> pq;
    
    
    // 힙을 사용하는 이유가 뭘까? 최소힙으로 만들어서. 루트 값만을 비교대상으로 사용하기 위함. 그리고 해당값이 알아서 정렬되기 때문ㅇ에 r      oot만 보고도 -1 여부 확인이 가능 
    
    //scovile -> pq
    
    for(int food : scoville){
        pq.push(food);
    }
    
    int num1;
    int num2;
    
    while(pq.top() < K){
        
        if(!pq.empty()){ num1 = pq.top(); pq.pop(); } 
        if(!pq.empty()){ num2 = pq.top(); pq.pop(); } else break ; // 앞에서 pop해서 뒤는 존재하지 않을 수도 있음. -1처리가 안되어 있음
        
        pq.push(num1 + num2 * 2);
        answer++;
        
        
    }
    
    while(pq.empty()){
        int test = pq.top();
        pq.pop();
        
        if(test < K) {answer = -1; break;}
        
        
    }
    
    
    return answer;
}