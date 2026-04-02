#include <iostream>
#include <vector>
using namespace std;

vector<int> p;

int find(int x){
    if(p[x] < 0){
        return x;
    }else return p[x] = find(p[x]);
}

bool uni(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return false;

    if(p[u] > p[v]){
        swap(u,v);
    }
    if(p[u] == p[v]){
        p[u]--;
    }
    p[v] = u;
    return true;

}



int main(){

    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int test;
    cin >> test;

    for(int i =1; i <= test; i++ ){
        int n;
        cin >> n;

        p = vector<int> (n,-1);
        int k; // 친구 관계 수 

        cin >> k;

        for(int j = 0; j < k; j++){
            int a, b;

            cin >> a >> b;
            uni(a,b);

        }

        
        int q; // 질문의 갯수
        cin >> q;
        cout << "Scenario "<< i << ":\n";
        for(int t = 0; t < q; t++){
            int a ,b;
            cin >> a >> b;
            if(find(a) == find(b)){
                cout << 1 <<"\n";
            }else{
                cout << 0 <<"\n";
            }
        }
        cout << "\n";

    }
}