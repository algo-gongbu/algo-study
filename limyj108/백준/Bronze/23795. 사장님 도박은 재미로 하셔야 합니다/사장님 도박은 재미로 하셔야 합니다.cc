#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, sum = 0;
    
    while (true) {
        cin >> n;
        if (n == -1)
            break;
        sum += n;
    }
    cout << sum;

    return 0;
}