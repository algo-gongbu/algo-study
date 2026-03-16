#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, ans = 0;
    string str;
    stack<char> stk;

    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> str;

        size_t len = str.size();

        for (size_t i = 0; i < len; i++) {
            if (stk.empty()) {
                stk.push(str[i]);
            }
            else if (stk.top() == str[i]) {
                stk.pop();
            }
            else {
                stk.push(str[i]);
            }
        }

        if (stk.empty()) {
            ans++;
        }
        else {
            while (!stk.empty()) {
                stk.pop();
            }
        }
    }
    cout << ans;

    return 0;
}