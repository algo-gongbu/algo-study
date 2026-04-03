#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, m;
    int count = 0;

    cin >> n >> m;
    vector<int> arr(n);

    for(int i =0; i < n; i++){
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end(), greater());

    for(int x : arr){

        // 자릿수가 맞지 않을 떄 
        if(m / x == 0) continue;

        // 자릿수가 맞거나. 금액이 동전 사이즈 보다 더 클때 
        count += (m / x);
        m = (m % x);
        
        if(x == 0){
            break;
        }


        
    }
    cout << count;

    
    
}