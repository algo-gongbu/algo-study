#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ;
    cin >> n;

    vector<pair<int,int>> test;

    for(int i =0; i < n; i++){
        int x,y;
       

        cin >> x >> y;
        test.push_back({x,y});
    }
    
    sort(test.begin(), test.end(),
                [](auto &a, auto &b){
                    if(a.second == b.second){
                        return a.first < b.first;
                    }return a.second < b.second;
                }
    );


    for(auto &p : test){
        cout << p.first << " " << p.second << "\n";
    }


}