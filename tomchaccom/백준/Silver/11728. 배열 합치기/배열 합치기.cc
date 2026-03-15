#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;

    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n+m);

    for(int i =0 ; i< n; i++){
        cin >> a[i];
    }
    for(int i =0 ; i< m; i++){
        cin >> b[i];
    }

    int aidx = 0; 
    int bidx =0;

    for(int i =0; i < n +m; i++){
        if(aidx == n) c[i] = b[bidx++];
        else if(bidx == m ) c[i] = a[aidx++];
        else if(a[aidx] <= b[bidx]) c[i] = a[aidx++];
        else c[i] = b[bidx++];
    }

    for(int i =0 ; i< n +m ;i++){
        cout << c[i] << " ";
    }
}