#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long low = 1, high = 1e18, t = times.size();
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long cnt = 0;
        for (int i = 0; i < t; i++) {
            cnt += (mid / times[i]);
        }
        if (cnt >= n) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    
    return answer;
}