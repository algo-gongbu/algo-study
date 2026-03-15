#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    for(auto v : my_string){
        if(v == letter[0]) continue;
        answer += v;
    }
    return answer;
}