#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int count = 0;
    int max = -1;

    vector<pair<int,int>> arr(n);

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        
        arr[i].first = num;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());

    for(int j = 0; j < n; j++){
        if(max < arr[j].second - j )
            max = arr[j].second - j;
    }
    cout << max + 1 << "\n";

}