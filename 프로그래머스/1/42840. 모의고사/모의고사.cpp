#include <string>
#include <vector>

using namespace std;

int ans1[5] = {1, 2, 3, 4, 5};
int ans2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int ans3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> ans;
    int N = answers.size(), max_val;
    int s1 = 0, s2 = 0, s3 = 0;
    
    for (int i = 0; i < N; i++) {
        if (ans1[i % 5] == answers[i]) {
            s1++;
        }
        if (ans2[i % 8] == answers[i]) {
            s2++;
        }
        if (ans3[i % 10] == answers[i]) {
            s3++;
        }
    }
    max_val = max(s1, max(s2, s3));
    if (max_val == s1)
        ans.push_back(1);
    if (max_val == s2)
        ans.push_back(2);
    if (max_val == s3)
        ans.push_back(3);
    
    return ans;
}