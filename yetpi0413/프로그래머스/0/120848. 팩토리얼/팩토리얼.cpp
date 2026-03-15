#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int fact = 1;
    while(fact <= n){
        ++answer;
        fact *= answer;
    }
    return answer-1;
}