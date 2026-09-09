#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i=1; i<=number; i++){
        int n = i;
        int num=1;
        for(int j=2; j*j<=n; j++){
            int e = 0;
            while(n%j==0){
                n /= j;
                e++;
            }
            num *= (e+1);
        }
        if (n>1) num*=2;
        answer += num>limit?power:num;
    }
    return answer;
}