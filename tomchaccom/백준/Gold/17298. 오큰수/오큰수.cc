#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;

    vector<int> arr(n);
    vector<int> answer(n);


    for(int j = 0 ; j < n ; j++){
        int number;
        cin >> number;
        
        arr[j] = number;
    }

    for(int i = 0 ; i < n ; i++){ // 인덱스로 조정하기       
        
        while(!st.empty() && arr[st.top()] < arr[i]){
            answer[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    while(!st.empty()){
        answer[st.top()] = -1;
        st.pop();
    }

    for(int t : answer){
        cout << t << " ";
    }

    
}