#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long m;

    cin >> n >> m;
    vector<int> metal;
    int start = 0;
    int end = n-1;
    int sum = 0;
    int count = 0;

    while(n--){
        int x;
        cin >> x;

        metal.push_back(x);
    }

    sort(metal.begin(), metal.end());

    while(start < end){
        sum = metal[start] + metal[end];

        if(sum > m){
            end--;
        }else if (sum < m){
            start++;
        }else{
            count++;
            end--;
        }

    }
    cout << count;
    
}