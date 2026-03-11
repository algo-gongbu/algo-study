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

    // sort(a.begin(), a.end());
    // 삽입 정렬로 대체해보기 

    // 첫번째는 뒤에꺼랑 비교해서 뒤에꺼가 더 작으면 변경 아니면 그대로 
    for(int j =1; j < n; j++){
        int key = a[j];
        int t = j -1;

        while(t >= 0 && a[t] > key){
            a[t+1] = a[t];
            t--;
        }
        a[t+1] = key;

    }

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