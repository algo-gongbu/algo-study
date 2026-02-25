#include <vector>
#include <algorithm>
using namespace std;

// 12:03
int solution(vector<int> nums)
{
    int answer = 0;
    // 가장 많은 종류의 포켓몬을 모으기 
    int k = nums.size() / 2;
    unordered_map<int,int> pocket;
    
    for(int mon : nums){
        pocket[mon]++;
    }
    int count = pocket.size();
    
    if(count <= k){
        answer = count;
    }else{
        answer = k;
    }
    
    
    // 그냥 다 세지 말고, map에 다 넣고, 포켓몬의 종류 갯수랑 n/2 == k를 비교
    // count == k answer =2 count > k k-count, count < k answer = count;
    return answer;
}