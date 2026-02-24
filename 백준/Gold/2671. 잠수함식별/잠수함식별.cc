#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;

void f(string temp) {
    // cout << temp << '\n';
    if (temp == "") {flag = true; return;}
    
    int index;
    if (temp[0] == '1') {
        if (temp[1] != '0') return;
        
        index = 2;
        while (index < temp.size() && temp[index] == '0') index++;
        
        if (index == 2 || index == temp.size()) return;
        
        while (index < temp.size() && temp[index] == '1') {index++; f(temp.substr(index));}
    }
    else {
        if (temp.size() <= 1) return;
        
        if (temp[1] == '1') f(temp.substr(2));
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string text;
    cin >> text;
    
    f(text);
    if (flag) cout << "SUBMARINE" << '\n';
    else cout << "NOISE" << '\n';
    
    return 0;
}