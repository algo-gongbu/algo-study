#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }else return abs(a) > abs(b);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, cmp> pq;
    vector<int> result;

    for(int i = 0; i < n; i++){
        int num;

        cin >> num;

        if(num == 0){
            
            if(pq.empty()){
                result.push_back(0);
            }else{
                result.push_back(pq.top());
                pq.pop();
            }
        }else{
            pq.push(num);
        }
    }

    for(int x : result){
        cout << x << "\n";
    }
    
}