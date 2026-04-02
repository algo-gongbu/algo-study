#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int start, int end, int mid) {
    if (n == 1) {
        cout << start << " " << end << "\n";
        return;
    }
    hanoi(n-1, start, mid, end);
    cout << start << " " << end << "\n";
    hanoi(n-1, mid, end, start);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    
    string a = to_string(pow(2, n));
	int x = a.find('.');
	a = a.substr(0, x);
	a[a.length() - 1] -= 1;	        
    
    cout << a << "\n";
    
    if(n <= 20) hanoi(n, 1, 3, 2);

    return 0;
}