#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    int m;
    cin >> n >> m;

    vector<vector<int>> nums(n + 1, vector<int>(n+1, 0));
    vector<vector<int>> p(n + 1, vector<int>(n+1, 0));
    vector<int> answer;

    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n ;j++){
            int number;
            cin >> number;

            nums[i][j] = number;
        }
    }

    p[1][1] = nums[1][1];

    // 부분 합 정의하기 
    for(int i = 1; i <= n; i++){
        for(int j =1; j <= n ;j++){
            if(i == 1){
                p[i][j] = nums[i][j] + p[i][j-1];
            }else if (j == 1){
                p[i][j] = nums[i][j] + p[i-1][j];
            }else{
                p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1] + nums[i][j];
            }
        }
    }


    
    for(int x = 0; x < m; x++){
        int x1,y1,x2,y2;
        int result;

        cin >> x1 >> y1 >> x2 >> y2;

        result = p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1];
        answer.push_back(result);
    }

    for(int x : answer){
        cout << x << "\n";
    }
}