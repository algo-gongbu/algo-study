#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int N = triangle.size();
    
    for (int r = 1; r < N; r++) {
        for (int c = 0; c <= r; c++) {
            if (c == 0) {
                triangle[r][c] += triangle[r - 1][c];   
            }
            else if (c == r) {
                triangle[r][c] += triangle[r - 1][c - 1];
            }
            else {
                triangle[r][c] += max(triangle[r - 1][c], triangle[r - 1][c - 1]);
            }
        }
        
    }
    
    return *max_element(triangle[N - 1].begin(), triangle[N - 1].end());
}