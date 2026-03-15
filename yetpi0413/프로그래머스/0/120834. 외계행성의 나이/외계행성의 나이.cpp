#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int age) {
    string answer = "";
    while(age>=10){
        answer += ((age % 10) + 'a');
        age /= 10;
    }
    answer += ((age % 10) + 'a');
    reverse(answer.begin(), answer.end());
    return answer;
}