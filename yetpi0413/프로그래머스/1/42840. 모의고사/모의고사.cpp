#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int n1[] = {1,2,3,4,5};
    int n2[] = {2,1,2,3,2,4,2,5};
    int n3[] = {3,3,1,1,2,2,4,4,5,5};
    
    int score[] = {0,0,0};
    
    for(int i=0; i<answers.size(); i++){
        if(n1[i%5]==answers[i]) score[0]++;
        if(n2[i%8]==answers[i]) score[1]++;
        if(n3[i%10]==answers[i]) score[2]++;
    }
    
    int best = max({score[0], score[1], score[2]});
    for(int i=0; i<3; i++){
        if(score[i]==best)  answer.push_back(i+1);
    }
    return answer;
}