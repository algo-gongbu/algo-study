#include <iostream>

using namespace std;

int main() {
    // C와 C++의 입출력 버퍼 동기화를 끊어서 속도를 극대화합니다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N; // 첫 번째 줄, 숫자의 개수 N 입력받기

    int count[10001] = {0}; 

    // N번 반복하면서 숫자를 하나씩 입력받습니다.
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        count[num]++;
    }
    
    for (int i = 1; i <= 10000; i++) {
        for (int j = 0; j < count[i]; j++) {
            cout << i << "\n";
        }
    }
    

    return 0;
}