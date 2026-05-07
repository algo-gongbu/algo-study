#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int max = sides[0]>sides[1]?sides[0]:sides[1];
    int min = sides[0]<sides[1]?sides[0]:sides[1];
    for(int i=max-min+1; i<max; i++){
        answer ++;
    }
    for(int i=max; i<min+max; i++){
        answer ++;
    }
    
    return answer;
}