#include <string>
#include <vector>

using namespace std;
int dfs(int index, int current_sum, vector<int> & numbers, int target){
    if(index == numbers.size()){
        if(current_sum == target) return 1;
        else return 0;
    } 
    
    int plus = dfs(index+1, current_sum + numbers[index], numbers,target);
    int minus = dfs(index+1, current_sum - numbers[index], numbers,target);
    return plus + minus;
    
}


int solution(vector<int> numbers, int target) { 
    return dfs(0,0,numbers,target);
}