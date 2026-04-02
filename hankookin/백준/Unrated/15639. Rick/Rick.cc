#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_set<string> rick_wont_do = {
        "give you up",
        "let you down",
        "run around and desert you",
        "make you cry",
        "say goodbye",
        "tell a lie and hurt you"
    };

    string input_action;
    if (!getline(cin, input_action)) return 0;
    string lower_input = "";
    for (char c : input_action) {
        lower_input += tolower(c);
    }

    if (rick_wont_do.find(lower_input) != rick_wont_do.end()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}