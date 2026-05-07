#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<int> tmp;
    for(auto s : score){
        tmp.push_back((s[0]+s[1]));
    }
    answer = tmp;
    sort(tmp.begin(),tmp.end(),greater<int>());
    for(int& n : answer){
        for(int i=0; i<tmp.size(); i++){
            if(tmp[i] == n){
                n = i+1;
                break;
            }
        }
    }
    return answer;
}