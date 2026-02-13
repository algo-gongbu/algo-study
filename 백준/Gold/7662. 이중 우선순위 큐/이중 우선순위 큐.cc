#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test;
    cin >> test;

    while(test--){
        int cases;
        cin >> cases;

        priority_queue<int> pq;  // 최대 힙
        priority_queue<int, vector<int>, greater<int>> pq2; // 최소 힙
        map<int,int> mp;

        while(cases--){
            char command;
            int num;
            cin >> command >> num;

            if(command == 'I'){
                pq.push(num);
                pq2.push(num);
                mp[num]++;
            }
            else if(command == 'D'){
                if(num == 1){ // 최대값 삭제

                    // max heap 정리 
                    while(!pq.empty() && mp[pq.top()] == 0)
                        pq.pop();

                    if(!pq.empty()){
                        int x = pq.top();
                        pq.pop();
                        mp[x]--;
                    }
                }
                else if(num == -1){ // 최소값 삭제

                    // min heap 정리 
                    while(!pq2.empty() && mp[pq2.top()] == 0)
                        pq2.pop();

                    if(!pq2.empty()){
                        int x = pq2.top();
                        pq2.pop();
                        mp[x]--;
                    }
                }
            }
        }

        while(!pq.empty() && mp[pq.top()] == 0)
            pq.pop();
        while(!pq2.empty() && mp[pq2.top()] == 0)
            pq2.pop();

        if(pq.empty() || pq2.empty())
            cout << "EMPTY\n";
        else
            cout << pq.top() << " " << pq2.top() << "\n";
    }
}
