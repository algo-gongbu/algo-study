#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> uid;
    int n = id_list.size(), cnt = 0;
    for (string id : id_list) {
        uid[id] = cnt++;
    }
    vector<int> answer(n, 0);
    vector<vector<bool>> R(n, vector<bool>(n, false));
    for (string str : report) {
        size_t pos = str.find(' ');
        string reporter = str.substr(0, pos), reported = str.substr(pos + 1);
        R[uid[reported]][uid[reporter]] = true;   
    }
    
    for (int r = 0; r < n; r++) {
        if (count(R[r].begin(), R[r].end(), true) < k)
            continue;
        
        for (int c = 0; c < n; c++) {
            if (R[r][c])
                answer[c] += 1;
        }
    }
    
    return answer;
}