#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int a, int b) {
    for(int i=2; i<=min(a, b); i++){
        if(a%i==0 && b%i==0){
            a/=i;
            b/=i;
            i=1;
            continue;
        }
    }
    if(b%2==0){
        while(b%2==0)   b/=2;
    }
    if(b%5==0){
        while(b%5==0)   b/=5;
    }
    if(b!=1)    return 2;
    return 1;
}