#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int len = phone_book.size();
    
    unordered_map<string,int> hash_map;
    for(string s : phone_book){
        hash_map[s] = 1;
    }
    
    for(int i =0; i < len; i++){
        
        string prefix; 
        
        for(int j = 0; j < phone_book[i].size(); j++){
            
            // 접두어 확인을 위해서 생성, 나는 접두어 개념을 그냥 똑같은 글자가 앞에 위치한다
            // 라고 생각했는데 해당 전화번호와 비슷하게 시작하는의 개념인듯 하다 
            prefix += phone_book[i][j]; 
            
            if(hash_map.find(prefix) != hash_map.end() && prefix != phone_book[i])                  {return false;}
        }
        
        
    }
    
    
    return answer;
}