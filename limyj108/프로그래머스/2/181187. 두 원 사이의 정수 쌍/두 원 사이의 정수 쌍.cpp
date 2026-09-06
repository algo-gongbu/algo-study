#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    for (int x = 1; x <= r2; x++) {
        int max_y = floor(sqrt(pow(r2, 2) - pow(x, 2))), min_y;
        if (r1 >= x) {
            min_y = ceil(sqrt(pow(r1, 2) - pow(x, 2)));
        }
        else {
            min_y = 0;
        }
        answer += (max_y - min_y + 1);
    }
    answer *= 4;
    return answer;
}