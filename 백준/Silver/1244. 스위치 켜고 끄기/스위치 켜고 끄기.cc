#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sCount, student;
    cin >> sCount;

    vector<int> switches(sCount + 1, 0);
    for(int i = 1; i <= sCount; i++){
        cin >> switches[i];
    }

    cin >> student;

    for(int j = 0; j < student; j++){
        int sex, card;
        cin >> sex >> card;

        if(sex == 1){
            // 남학생: card의 배수 전부 토글
            for(int k = card; k <= sCount; k += card){
                switches[k] = !switches[k];
            }
        } else {
            // 여학생: 대칭 최대 확장 후 [l..r] 전체 토글
            int l = card, r = card;
            while(l - 1 >= 1 && r + 1 <= sCount && switches[l - 1] == switches[r + 1]){
                l--;
                r++;
            }
            for(int i = l; i <= r; i++){
                switches[i] = !switches[i];
            }
        }
    }

    // 출력: 20개마다 줄바꿈
    for(int i = 1; i <= sCount; i++){
        cout << switches[i] << ' ';
        if(i % 20 == 0) cout << '\n';
    }
    if(sCount % 20 != 0) cout << '\n';

    return 0;
}