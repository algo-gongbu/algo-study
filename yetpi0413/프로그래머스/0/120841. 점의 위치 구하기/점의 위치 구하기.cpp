#include <string>
#include <vector>

using namespace std;

int solution(vector<int> dot) {
    int answer = 0;
    if(dot.front()>0){
        if(dot.back()>0)    answer=1;
        else    answer=4;
    }
    else{
        if(dot.back()>0)    answer=2;
        else    answer=3;
    }
    return answer;
}