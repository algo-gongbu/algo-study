#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int data;
    int question;
    cin >> data >> question;

    vector<int> nums(data);
    vector<int> part(data);
    vector<int> answer;

    for(int i =0; i< data; i++){
        int number;

        cin >> number;
        nums[i] = number;
    }
    part[0] = nums[0];

    for(int j = 1; j < data; j++){
        part[j] = part[j-1] + nums[j];
    }

    for(int k =0; k < question; k++){
        int start, end;
        int result;

        cin >> start >> end;
        result = part[end -1] - part[start -2];

        answer.push_back(result);
    }
    for(int x : answer){
        cout << x << "\n";
    }
    
}