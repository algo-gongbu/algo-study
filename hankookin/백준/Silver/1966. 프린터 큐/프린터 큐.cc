#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        vector<int> priorities;

        for (int i = 0; i < n; i++) {
            int priority;
            cin >> priority;
            q.push({priority, i});
            priorities.push_back(priority);
        }

        sort(priorities.begin(), priorities.end(), greater<int>());

        int print_count = 0; 
        int p_idx = 0;    

        while (!q.empty()) {
            int current_priority = q.front().first;
            int current_index = q.front().second;
            q.pop();
            
            if (current_priority == priorities[p_idx]) {
                print_count++;
                p_idx++; 

                if (current_index == m) {
                    cout << print_count << endl;
                    break;
                }
            } 
            else {
                q.push({current_priority, current_index});
            }
        }
    }

    return 0;
}