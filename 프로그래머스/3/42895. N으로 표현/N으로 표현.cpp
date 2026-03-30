#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if(N == number) return 1;
    int answer = 0;
    
    vector<unordered_set<long long>> dp(9);
    long long n_continuous = 0;
    
    for(int i = 1; i <= 8; i++){
        n_continuous = n_continuous * 10 + N;
        dp[i].insert(n_continuous);
    }
    
    for(int i = 1; i<= 8; i++){
        for(int j = 1; j < i; j++){
            for(long long a : dp[j]){
                for(long long b : dp[i - j]){
                
                dp[i].insert(a + b);
                dp[i].insert(a - b);
                dp[i].insert(a * b);
                if(b != 0) dp[i].insert(a/b);
            }
        }
        
            if(dp[i].find(number) != dp[i].end()){
                return i;
            }
        }
    }
    
    
    return -1;
}