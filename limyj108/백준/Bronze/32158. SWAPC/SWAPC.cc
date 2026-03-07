#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, p_ptr = 0, c_ptr = 0;
    string str, copy;

    cin >> S >> str;
    copy = str;

    while (p_ptr < S && c_ptr < S) {
        while (str[p_ptr] != 'P') {
            p_ptr++;
            if (p_ptr >= S)
                break;
        }
        while (str[c_ptr] != 'C') {
            c_ptr++;
            if (c_ptr >= S)
                break;
        }

        if (p_ptr < S && c_ptr < S) {
            copy[c_ptr] = str[p_ptr];
            copy[p_ptr] = str[c_ptr];
        }
        p_ptr++;
        c_ptr++;
    }
    cout << copy;

    return 0;
}