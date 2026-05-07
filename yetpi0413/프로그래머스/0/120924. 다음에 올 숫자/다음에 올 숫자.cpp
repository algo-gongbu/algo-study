#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    int d = common[1]-common[0];
    int r = common[0]!=0?common[1]/common[0]:0;
    if(common[1]+d==common[2]){
        answer = common.back()+d;
    }
    else if(common[1]*r==common[2]){
        answer = common.back()*r;
    }
    return answer;
}