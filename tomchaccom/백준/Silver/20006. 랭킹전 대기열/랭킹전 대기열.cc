#include <bits/stdc++.h>
using namespace std;

struct Room {
    int base_level;  // 방 기준 레벨
    vector<pair<int,string>> players;  // (레벨, 닉네임)
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int p, m;
    cin >> p >> m;

    vector<Room> rooms;

    for(int i = 0; i < p; i++){
        int level;
        string nickname;
        cin >> level >> nickname;

        bool joined = false;

        // 기존 방들 탐색 (먼저 생성된 순서)
        for(auto &room : rooms){
            if(room.players.size() < m &&
                room.base_level - 10 <= level &&
                level <= room.base_level + 10){
                
                room.players.push_back({level, nickname});
                joined = true;
                break;
            }
        }

        // 입장 가능한 방이 없으면 새 방 생성
        if(!joined){
            Room new_room;
            new_room.base_level = level;
            new_room.players.push_back({level, nickname});
            rooms.push_back(new_room);
        }
    }

    // 출력
    for(auto &room : rooms){
        if(room.players.size() == m)
            cout << "Started!\n";
        else
            cout << "Waiting!\n";

        // 닉네임 기준 정렬
        sort(room.players.begin(), room.players.end(),
            [](auto &a, auto &b){
                return a.second < b.second;
            });

        for(auto &player : room.players){
            cout << player.first << " " << player.second << "\n";
        }
    }
}
