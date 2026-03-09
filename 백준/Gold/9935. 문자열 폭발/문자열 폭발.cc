#include <iostream>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str, bomb, ans;
	cin >> str >> bomb;

	int str_len = str.size(), bomb_len = bomb.size();

	for (int i = 0; i < str_len; i++) {
		ans += str[i];
		int ans_len = ans.size();
		bool is_bomb = true;

		if (ans_len >= bomb_len) {
			for (int j = 0; j < bomb_len; j++) {
				if (ans[ans_len - bomb_len + j] != bomb[j]) {
					is_bomb = false;
					break;
				}
			}

			if (is_bomb) {
				for (int j = 0; j < bomb_len; j++) {
					ans.pop_back();
				}
			}
		}
	}

	if (ans.empty()) {
		cout << "FRULA";
	}
	else {
		cout << ans;
	}

	return 0;
}