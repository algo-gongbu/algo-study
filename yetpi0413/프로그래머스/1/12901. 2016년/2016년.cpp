#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int mon[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    for(int i=a-2; i>=0; i--){
        sum += mon[i];
    }
    sum += b;
    sum %= 7;
    
    switch(sum){
        case 1:
            answer = "FRI";
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
        case 0:
            answer = "THU";
            break;
    }
    return answer;
}