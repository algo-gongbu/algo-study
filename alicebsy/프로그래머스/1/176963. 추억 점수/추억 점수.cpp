#include <string>
#include <vector>
#include <map> 

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> score_map;


    for (int i = 0; i < name.size(); i++) {
        score_map[name[i]] = yearning[i];
    }


    for (int i = 0; i < photo.size(); i++) {
        int sum = 0;

        for (int j = 0; j < photo[i].size(); j++) {
            string person = photo[i][j];
            

            if (score_map.count(person)) {
                sum += score_map[person];
            }
        }
        answer.push_back(sum); 
    }

    return answer;
}