#include <string>
#include <vector>

using namespace std;

int timeToInt(string pos){
    
    int mm = stoi(pos.substr(0,2));
    int ss = stoi(pos.substr(3,2));
    
    int second = mm * 60 + ss;
    return second;
}

string intToTime(int time){
    int mm = time / 60;
    int ss = time % 60;
    string result = "";
    
    string x ="";
    if(mm < 10){
        result = "0" + to_string(mm);
    }else{
        result += to_string(mm);
        
    }
    result += ":";
    string y ="";
    if(ss < 10){
        
        y += "0";
        y += to_string(ss);
        result += y;
    }else{
        result += to_string(ss);
    }
    return result;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int videoTime = timeToInt(video_len);
    int current = timeToInt(pos);
    int start = timeToInt(op_start);
    int end = timeToInt(op_end);
    
    for(string command : commands){
        
        if(start <= current && current <= end){
            current = end;
        }
        
        if(command == "prev"){
            if(current -10 >=  0){
                current = current -10;
            }else{
                current = 0;
            }
        }else if(command == "next"){
            if(current + 10 <= videoTime){
                current = current + 10;
            }else{
                current = videoTime;
            }
        }
    }
    
    if(start <= current && current <= end){
            current = end;
    }
    answer = intToTime(current);
    
    
    return answer;
}

