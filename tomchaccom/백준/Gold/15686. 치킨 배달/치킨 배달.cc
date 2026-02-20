#include <bits/stdc++.h>
using namespace std;

int calDist(vector<pair<int,int>>& chicken,
            vector<vector<int>>& city, int n){ //치킨집 위치를 제공해주면 전체에서 최소 치킨 거리만 구함
    int dist = 0;

    for(int i =0; i < n; i++){
        
        for(int j =0; j < n; j++){

            int temp = 0; 
            if(city[i][j] == 1){

                int mn = INT_MAX;
                for(auto &chick : chicken){
                    temp = abs(chick.first -i) + abs(chick.second -j);
                    mn = min(mn,temp);
                }
                dist += mn; // 모든 집에 대해서 치킨집과의 거리를 저장
            }

        }
    }
    return dist;
}


int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;
    vector<vector<int>> city(n, vector<int>(n));
    vector<pair<int,int>> chicken;
    vector<pair<int,int>> remain;

    int kan;

    for(int i =0; i < n; i++){
        for(int j =0; j < n; j++){
            cin >> kan;
            city[i][j] = kan;

            if(kan == 2){
                chicken.push_back({i,j});
            }
        }
    }

    int answer = INT_MAX;

    // 조합을 구현해서 치킨집을 함수에 넘겨주기
    int len = chicken.size(); 

    vector<int> comb(len,0);

    for(int i = 0; i < m; i++){
        comb[i] = 1; // 111 00 만든 상태 
    }

    do{
        vector<pair<int,int>> selected;

        for(int i = 0; i < len; i++){
            if(comb[i] == 1){
                selected.push_back(chicken[i]);
            }
        }
        int cityDist = calDist(selected, city,n);
        answer = min(answer, cityDist);

    }while(prev_permutation(comb.begin(), comb.end()));

    cout << answer;

    

}