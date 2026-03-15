#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;

    cin >> n >> l;
    deque<pair<int,int>> window;
    vector <int> result;

    // 덱을 이용해서 강제로 정렬 효과를 보기 


    for(int index =1; index <= n; index++){
        int number;
        cin >> number;
        
        while(!window.empty() && window.back().second > number){
            window.pop_back();
        }
        window.push_back({index, number});


        if(window.front().first < index - l + 1){
            window.pop_front();
        }
        result.push_back(window.front().second);
    
    }
    
    for(int res : result){
        cout << res << " ";
    }

}