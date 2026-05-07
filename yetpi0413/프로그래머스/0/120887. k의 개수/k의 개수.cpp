#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    for(int l = i; l<=j; l++){
        for(char c : to_string(l)){
            if((c-'0')==k)   answer++;
        }
    }
    return answer;
}