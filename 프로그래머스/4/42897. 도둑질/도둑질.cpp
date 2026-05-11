#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int N = money.size();
    int d1 = 0, d2 = 0, prev_2 = 0, prev_1 = 0;
    
    for (int n = 1; n < N; n++) {
        d1 = max(prev_1, prev_2 + money[n]);
        prev_2 = prev_1;
        prev_1 = d1; 
    }
    
    prev_2 = 0, prev_1 = money[0];
    for (int n = 1; n < N - 1; n++) {
        d2 = max(prev_1, prev_2 + money[n]);
        prev_2 = prev_1;
        prev_1 = d2;
    }
    
    return max(d1, d2);
}