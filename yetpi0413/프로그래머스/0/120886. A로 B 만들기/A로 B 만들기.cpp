#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string before, string after) {
    map<char, int> b;
    map<char, int> a;
    
    for(char c : before){
        b[c]++;
    }
    for(char c : after){
        a[c]++;
    }
    
    for(auto e : b){
        if(a.find(e.first)==a.end()||e.second!=a[e.first])  return 0;
    }
    return 1;
}