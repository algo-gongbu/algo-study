#include <bits/stdc++.h>
using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, d;
    int x,y;

    cin >> n >> m ;
    cin >> x >> y >> d;
    int room[50][50];
    int count =0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            cin >> room[i][j]; 
        }
    }

    int exit = 1;
    while(exit){

        bool moved = false;

        int current = room[x][y];
        int flag = 0;

        if(current == 0){ // 청소하지 않았다면 청소 
            room[x][y] = 2;
            count++;
        }
        // 상하좌우 확인 & 청소 안한 곳을 못 찾으면 후진
        for(int i =0; i < 4 ; i++){
            d = (d + 3) % 4;
            
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!room[nx][ny]){
                x = nx;
                y = ny;
                moved = true;

                break;
            }

        }
        // x 또는 y 값의 변화가 없으면, 후진
        if(!moved){
            int bx = x - dx[d];
            int by = y - dy[d];

            if(room[bx][by] == 1) break;

            x = bx;
            y = by;

        }


    }
    cout << count;

}