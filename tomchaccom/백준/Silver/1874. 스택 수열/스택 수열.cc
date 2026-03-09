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
    vector<char> result;
    vector<int> arr(n+1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int current = 1;
    int index = 1;

    while(index <= n){

        // 필요한 숫자까지 push
        while(current <= arr[index]){
            st.push(current);
            result.push_back('+');
            current++;
        }

        // pop 가능 여부 확인
        if(!st.empty() && st.top() == arr[index]){
            st.pop();
            result.push_back('-');
            index++;
        }
        else{
            cout << "NO";
            return 0;
        }
    }

    for(char c : result){
        cout << c << "\n";
    }

    return 0;
}