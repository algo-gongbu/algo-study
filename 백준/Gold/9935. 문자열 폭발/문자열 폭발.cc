#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    string bomb;
    string result;

    cin >> str >> bomb;

    // 일단 str에 다 추가하고, 만약. c 값이 bomb 마지막 단어라면, 
    // 나머지도 읽어보고 pop_back()

    for(char c : str){

        result += c;

        if(c == bomb[bomb.size() -1]){
            // 이제 꺼내서 확인. 
            if(result.size() >= bomb.size() &&
            result.substr(result.size() - bomb.size(), bomb.size()) == bomb)
                                                    {
                for(int i =0; i < bomb.size(); i++){
                    result.pop_back();
                }
            }
        }
    }
    if(!result.size()){
        cout << "FRULA";
    }else{
        cout << result << "\n";
    }

    

}