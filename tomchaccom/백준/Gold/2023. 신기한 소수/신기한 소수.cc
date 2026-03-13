#include <iostream>
#include <vector>

using namespace std;

int n;

bool isprime(int num){
    for(int i =2; i * i <= num; i++){
        if(num %i == 0){
            return false;
        }
    }
    return true;
}

void dfs(int num, int jarisu){
    if(jarisu == n){
        if(isprime(num)){
            cout << num << "\n";
        }
        return;
    }

    for(int i = 1; i < 10; i++){
        if(i % 2 == 0){
            continue;
        }
        if(isprime(num * 10 + i)){
            dfs(num * 10 +i , jarisu + 1);
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    // 신기한 소수 
    // 7331 은 7도 소수 73 도 소수 733도 소수 7331도 소수인 수를 의미 
    // 2, 3, 5, 7 부터 시작 

    
    cin >> n;

    dfs(2,1);
    dfs(3,1);
    dfs(5,1);
    dfs(7,1);

    
}