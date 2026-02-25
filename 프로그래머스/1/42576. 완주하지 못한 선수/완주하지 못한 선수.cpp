#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, vector<int>> mp;
    map<string, vector<int>> mp2;
    
    for(int i =0; i< participant.size(); i++){
        mp[participant[i]].push_back(i); // 인덱스를 넣기 
    }
    // 1. 동명이인 존재할 경우의 처리 -> 인덱스를 넣고 똑같은 map을 하나 더 만들어서, size 비교하기?
    // 2. 일반적으로 완주자 명단에 없는 동명이인이 없을 때의 처리, 원래 하던 대로 처리
    
    for(int j = 0; j < completion.size(); j++){
        mp2[completion[j]].push_back(j);
    }
    
    for(string name : participant){
        if(mp[name].size() != mp2[name].size()){
            answer = name;
            break;
        }
        
    }
    
    return answer;
}