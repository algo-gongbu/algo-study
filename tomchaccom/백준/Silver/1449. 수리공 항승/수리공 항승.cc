#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n , l;
    int x;
    int tape = 0;
    int term = 1;

    cin >> n >> l; // 물이 새는 곳과 테이프 위치 입력
    vector<int> pipe(n); // 물이 새는 곳을 저장 

    
    for(int i =0; i< n; i++){ // 물이 새는 곳을 저장
        cin >> x;
        pipe[i] = x;
        
    }
    sort(pipe.begin(), pipe.end());

    for(int j = 0; j < n;){
        int s = pipe[j];
  
        // 1. 현재 위치에 물이 새는 곳에 테이프 붙이기 
        tape++;
        // 2. 테이프를 붙이고 난 후, 다른 물이 새는 곳까지 한번에 테이프로 막아지는지 확인하기
        while(j != n-1 && pipe[j+1] - s < l ){
          j++;
            
        }
        // 2 -1. 막아진다면, 막을 수 있는 곳은 막고, 막을 수 없는 곳부터 다시 반복문 시작하기
        // 2- 2. 안막아 진다면 반복문 넘어가기 
        j++;
    }
    cout << tape;

    
}