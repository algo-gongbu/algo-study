#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 24)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
string res;
int op[100];

string mul_or_div(char c);

string f() {
    char c, next_c;
    int index_op;
    string temp;
    while ((c = getchar()) != EOF) {
        if (c == '\n') continue;
        if (c == '(') temp += f();
        if (c == ')') return temp;

        if (c >= 'A' && c <= 'Z') temp += c;
        else if (c == '*' || c == '/') temp += mul_or_div(c);
        else if (c == '+' || c == '-') {
            if ((next_c = getchar()) == '(') temp += f();
            else temp += next_c;

            while (c == '+' || c == '-') {
                next_c = getchar();
                if (c == '\n') continue;
                if (next_c == EOF || next_c == ')') {temp += c; return temp;}
                else if (next_c == '(') temp += f();
                else if (next_c == '*' || next_c == '/') temp += mul_or_div(next_c);
                else if (next_c == '+' || next_c == '-') {
                    temp += c;
                    c = next_c;
                    if ((next_c = getchar()) == '(') temp += f();
                    else temp += next_c;
                }
            }
        }
    }
    return temp;
}

string mul_or_div(char c) {
    char next_c;
    string temp;

    next_c = getchar();
    if (next_c == '(') temp += f();
    else temp += next_c;
    temp += c;
    
    return temp;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    res += f();

    cout << res << '\n';

    return 0;
}