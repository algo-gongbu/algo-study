#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int max = 0;
    map<int, int> num;
    
    for(int n : array){
        num[n]++;
    }
    
    for(auto n : num){
        if(n.second > max){
            answer = n.first;
            max = n.second;
        }
        else if(n.second == max) {
            answer = -1;
        }
    }
    
    return answer;
}