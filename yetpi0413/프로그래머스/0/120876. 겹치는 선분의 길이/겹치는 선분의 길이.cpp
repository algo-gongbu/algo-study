#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    map<int, int> dots;
    for(auto l : lines){
        for(int i=l[0]; i<l[1]; i++){
            dots[i]++;
        }
    }
    for(auto len : dots){
        if(len.second>=2)  answer ++;
    }
    return answer;
}