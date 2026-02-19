#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n ;
    cin >> n;

    vector<pair<int,string>> test;

    for(int i =0; i < n; i++){
        int age;
        string name;

        cin >> age >> name;
        test.push_back({age,name});
    }
    
    stable_sort(test.begin(), test.end(),
                [](auto &a, auto &b){
                    return a.first < b.first;
                }
    );


    for(auto &p : test){
        cout << p.first << " " << p.second << "\n";
    }


}