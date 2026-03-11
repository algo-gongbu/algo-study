#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> s(n);

    for(int i =0; i< n; i++){
        int num;
        cin >> num;
        
        a[i] = num;
    }

    sort(a.begin(), a.end());

    s[0] = a[0];
    for(int i = 1; i < n; i++){
        s[i] = s[i-1] + a[i];
    }
    int result = 0;
    
    for(int x : s){
        result+= x;
    }
    cout << result;
    
}