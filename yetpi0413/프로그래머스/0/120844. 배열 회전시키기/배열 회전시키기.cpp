#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers, string direction) {
    vector<int> answer;
    int first = numbers.front();
    int last = numbers.back();
    if(direction == "right"){
        int tmp = numbers[1];
        for(int i=1; i<numbers.size()-1; i++){
            numbers[i] = first;
            first = tmp;
            tmp = numbers[i+1];   
        }
        numbers[numbers.size()-1] = first;
        numbers[0] = last;
    }  
    else{
        int tmp = numbers[numbers.size()-2];
        for(int i=numbers.size()-2; i>0; i--){
            numbers[i] = last;
            last = tmp;
            tmp = numbers[i-1];
            numbers[i-1] = numbers[i];
        }
        numbers[0] = last;
        numbers[numbers.size()-1] = first;
    }
    answer = numbers;
    return answer;
}