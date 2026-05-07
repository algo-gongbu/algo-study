#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j]==1){
                if(i-1>=0){
                    if(j-1>=0&&board[i-1][j-1]==0)  board[i-1][j-1]=-1;
                    if(j+1<board[0].size()&&board[i-1][j+1]==0) board[i-1][j+1]=-1;
                    if(board[i-1][j]==0)    board[i-1][j]=-1;
                }
                if(i+1<board[0].size()){
                    if(j-1>=0&&board[i+1][j-1]==0)  board[i+1][j-1]=-1;
                    if(j+1<board[0].size() && board[i+1][j+1]==0)   board[i+1][j+1]=-1;
                    if(board[i+1][j]==0)    board[i+1][j]=-1;
                }
                if(j-1>=0&&board[i][j-1]==0)  board[i][j-1]=-1;
                if(j+1<board[0].size()&&board[i][j+1]==0)   board[i][j+1]=-1;
            }
        }
    }
            
    for(auto arr : board){
        answer += count_if(arr.begin(), arr.end(), [](int n){
            return n==0;
        });
    }
    return answer;
}