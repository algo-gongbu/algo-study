#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long n;
    cin >> n;
    long long sum =1;
    int count =1;
    int start = 1;
    int end = 1;

    while(end != n){
        if(sum < n){
            sum += ++end;
        }else if(sum > n){
            sum -= start++;
        }else{
            count++;
            sum += ++end;
        }
    }
    cout << count;
}