#include <iostream>
#include <climits>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

#define INF (1 << 28)

int n, m, h, maximum = INT_MIN, minimum = INT_MAX, ans;
bool flag;
string text, target, stack;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> text >> target;

    int index = -1, temp, target_length = (int) target.length();
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == target[target_length - 1]) {
            temp = 0;
            while (temp <= target_length - 2) {
                if (stack[index - temp] == target[target_length - 2 - temp]) temp++;
                else break;
            }
            if (temp == target_length - 1) {
                for (int i = 0; i < temp; i++) stack.pop_back();
                index -= temp; 
                continue;
            }
        }
        stack += text[i]; 
        index++;
    }

    if (index == -1) cout << "FRULA" << '\n';
    else cout << stack << '\n';

    return 0;
}