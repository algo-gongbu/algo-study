#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    int idx = 0;
    for(int i=0; i<k; i++){
        if(idx>=numbers.size()) idx -= numbers.size();
        answer = numbers[idx];
        idx+=2;
    }
    return answer;
}