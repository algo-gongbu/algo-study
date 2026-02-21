#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int skillTime = bandage[0];
    int second = bandage[1];
    int bonus = bandage[2];
    int mx = health;
    
    int yeon = 0;

    int end = attacks[attacks.size() - 1][0]; // 몬스터의 마지막 공격 
    queue<pair<int,int>> q;
    
    for(int i = 0; i< attacks.size(); i++){
        int x = attacks[i][0];
        int y = attacks[i][1];
        
        q.push({x,y});
    }

    for(int i = 1; i <= end; i++){
        
        auto [atime, damage] = q.front();
        
        if(atime == i){
            q.pop();
            health -= damage;
            yeon = 0;
            
            if(health <= 0)
                break;
        }else{
            health += second;
            yeon++;
            
            if(health > mx){
                health = mx;
            }
            
            if(yeon == skillTime){
                health += bonus;
                yeon = 0;
                
                if(health > mx){
                    health = mx;
                }
            }
            
        }
        
    }
    
    if(health <= 0){
        answer = -1;
    }else{
        answer = health;
    }
    
    return answer;
}