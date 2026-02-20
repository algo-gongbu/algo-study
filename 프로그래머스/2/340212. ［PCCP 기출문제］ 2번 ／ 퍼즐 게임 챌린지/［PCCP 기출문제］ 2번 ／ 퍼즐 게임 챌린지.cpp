#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;
    
    int left = 1;
    int right = 100000; 
    
    while(left <= right){
        int level = left + (right - left) / 2; 
        
        long long time = times[0];
        
        for(int i = 1; i < diffs.size(); i++){
            if(diffs[i] <= level){
                time += times[i];
            } else {
                long long diff = (long long)diffs[i] - level;
                time += diff * (times[i] + times[i-1]) + times[i];
            }
            
            if(time > limit) break;
        }
        
        if(limit >= time){
            // 현재 level로 해결 가능하므로 기록해두고,
            // 더 작은 level에서도 가능한지 확인하기 위해 범위를 왼쪽으로 좁힘
            answer = level;
            right = level - 1; 
        } else {
            // 해결 불가능하므로 level을 더 높여야 함
            left = level + 1;
        }
    }
    return answer;
}