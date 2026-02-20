#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int mid = (array.size())/2;
    
    for(int j=0; j<array.size(); j++){
        for(int i=0; i<array.size()-1; i++){
            if(array.at(i)>array.at(i+1)){
                int tmp = array.at(i);
                array.at(i) = array.at(i+1);
                array.at(i+1) = tmp;
            }
        }
    }
    int answer = array.at(mid);
    return answer;
}