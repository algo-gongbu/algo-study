#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    queue<int> card;

    for(int i =1; i <= n; i++){
        card.push(i);
    }
    
    
    while(card.size() > 1){

        if(!card.empty()) card.pop();
        card.push(card.front());
        card.pop();
    }

    cout << card.front();

    
}