#include <string>
#include <vector>

using namespace std;

string solution(string polynomial) {
    string answer = "";
    int x = 0;
    int num = 0;
    int flag = 0;
    for(char c : polynomial){
        if(flag!=0){
            if(c=='x'){
                x+=flag;
                flag=0;
                continue;
            }
            else if(c==' '){
                num+=flag;
                flag=0;
                continue;
            }
            else{
                flag = flag*10 + (c-'0');
                continue;
            }
        }
        
        if(c=='x'){
            x++;
            flag = 0;
        }
        else if(c==' ') flag = 0;
        else if(c=='+') flag = 0;
        else    flag = (c-'0');
    }
    if(flag!=0) num += flag;
    
    if(x>0){
        if(x>1) answer += to_string(x);
        answer += "x";
    }
    if(num>0){
        if(x>0) answer += " + ";
        answer += to_string(num);
    }
    return answer;
}