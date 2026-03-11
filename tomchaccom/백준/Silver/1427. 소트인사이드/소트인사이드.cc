#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<int> arr;
    for(int i =0; i < s.size(); i++){
        arr.push_back(s[i] -'0');
    }
    sort(arr.begin(), arr.end(), greater<int>());

    for(int x : arr){
        cout << x;
    }

}