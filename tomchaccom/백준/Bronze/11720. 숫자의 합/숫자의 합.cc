#include <stdio.h>

int main(){
    
    int number; // 더할 숫자의 갯수
    char nospace[100]; // 공백 없이 입력되는 수
    int sum = 0;
    
    scanf("%d",&number);
    scanf("%s",nospace);
    
    
    for(int i = 0; i < number; i++){
        sum += nospace[i] - '0';
    }
    
    printf("%d",sum);
    
    return 0;
    
}