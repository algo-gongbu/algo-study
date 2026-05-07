#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    sort(numlist.begin(), numlist.end(), [n](int a, int b){
        int dist_a = abs(a-n);
        int dist_b = abs(b-n);
        
        if(dist_a==dist_b){
            return a>b;
        }
        return dist_a < dist_b;
    });
    return numlist;
}