#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int garo = 0;
    int sero = 0;
    
    // 편의상 긴쪽을 가로, 짧은 쪽을 세로로 설정.. 이러면 회전을 고려하지 않아도 된다 
    for(int i =0; i < sizes.size(); i++){
        
        int w = max(sizes[i][0] , sizes[i][1]);
        int h = min(sizes[i][0] , sizes[i][1]);
        
        
        // 1. w가 garo보다 길때 garo += (w - garo)
        // 2/ h가 sero보다 길때 sero += (h - sero)
        // 3. 둘다 
        
        garo = max(garo, w);
        sero = max(sero, h);
        
        
        
    }
    return garo * sero;
    
}