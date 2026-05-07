#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    for(auto id : db){
        if(id_pw[0] == id[0]){
            if(id_pw[1]==id[1]){
                answer = "login";
                break;
            }
            else{
                answer = "wrong pw";
                break;
            }
        }
        else{
            answer = "fail";
            continue;
        }
    }
    return answer;
}