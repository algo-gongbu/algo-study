#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    for(string word : dic){
        int flag = 0;
        map<char, int> num;
        for(char c : word){
            num[c]++;
        }
        for(string s : spell){
            if(num[s[0]]==1)   flag++;
        }
        if(flag==spell.size())  return 1;
    }
    return 2;
}