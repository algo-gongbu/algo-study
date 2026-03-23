#include <bits/stdc++.h>

using namespace std;

#define INF (1 << 28)
#define N (int) 2e4
#define ll long long

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
string text;

void f(string temp) {
    // cout << temp << '\n';
    if (temp == "") {flag = true; return;}
    else if (temp[0] == '0' && temp.size() >= 2) {
        if (temp[1] == '1') f(temp.substr(2));
        if (flag) return;
    }
    else if (temp[0] == '1' && temp.size() >= 4) {
        if (temp[1] != '0') return;

        int idx = 2;
        while (idx < temp.size() && temp[idx] == '0') ++idx;
        if (idx == 2 || idx == temp.size()) return;
        
        while (idx < temp.size() && temp[idx] == '1') {
            f(temp.substr(++idx)); 
            if (flag) return;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    while (n--) {
        cin >> text;

        flag = false;
        f(text);

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}