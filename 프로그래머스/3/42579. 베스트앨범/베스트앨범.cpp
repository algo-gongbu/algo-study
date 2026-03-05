#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // 재생시간을 키로? 장르를 키로?
    
    unordered_map<string,vector<pair<int,int>>> mp;
    unordered_map<string, int> total; // 장르별 재생시간이 가장 긴것 저장.
    
    
    for(int i =0; i < genres.size(); i++){
        mp[genres[i]].push_back({plays[i] ,i});
        total[genres[i]]+= plays[i];
    }
    
    vector<pair<string,int>> genre_total(total.begin(), total.end());
    
    // 장르별 재생시간을 비교해서 내림차순으로 정렬 
    sort(genre_total.begin(), genre_total.end(),
         [](auto &a, auto &b){
             return a.second > b.second;
         });
    
    // mp 맵 내부의 재생시간을 비교해서 정렬하고, 재생시간이 같다면, 인덱스 내림차순으로 정렬 
    for(auto &a : mp){
        sort(a.second.begin(), a.second.end(), 
             [](auto &x , auto &y){
                 if(x.first == y.first){
                     return x.second < y.second;
                 }return x.first > y.first;
                 
             });
    }
    for(auto g : genre_total){
        auto &song = mp[g.first]; // 장르별 재생시간과 인덱스 pair가 song에 저장 
        for(int i = 0; i < song.size() && i < 2; i++){
            answer.push_back(song[i].second);
        }
        
        
    }

    return answer;
}