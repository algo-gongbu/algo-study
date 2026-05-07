#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if(s[0]=='+'){
        s.erase(0,1);
        answer = stoi(s);
    }
    else if(s[0]=='-'){
        s.erase(0,1);
        answer = stoi(s);
        answer *= -1;
    }
    else{
        answer = stoi(s);
    }
    return answer;
}