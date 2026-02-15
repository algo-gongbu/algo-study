#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    map<string, int> mp; // 초기 사이즈 설정이 필요없다
    int mx = 0;

    for(int i =0; i< n; i++){
        string line;
        cin >> line;

        mp[line]++;

    }
    
    for(auto& p : mp){
        mx = max(mx, p.second);
    }
    
    for(auto& p : mp){
        if(p.second == mx){
            cout << p.first;
            break;
        }
    }


}