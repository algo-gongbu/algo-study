#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 선택정렬. 범위내에서 최소 또는 최대값 스캔후 현재 인덱스에 할당 
    string s;
    cin >> s;
    int Max = 0;

    vector<int> a(s.size());

    for(int i = 0; i< s.size(); i++){
        a[i] = s[i] - '0'; // 숫자로 먼저 저장
    }

    for(int j =0; j < s.size() -1; j++){
        Max = j;
        for(int k = j + 1; k < s.size(); k++){
            
            // 최댓값을 앞으로 위치시키기
            if(a[Max] <= a[k]){
                Max = k;
            }
            
        }
        swap(a[j], a[Max]);


    }    
    for(int x : a){
        cout << x;
    }
}