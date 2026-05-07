#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int coupon = chicken;
    int left = 0;
    answer += coupon/10;
    coupon = coupon/10 + coupon%10;
    while(coupon >= 10){
        answer += coupon/10;
        coupon = coupon/10 + coupon%10;
    }
    return answer;
}