#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int k;
	char c;
	string str, encoded, decoded = "";
	map<string, char> m;

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> c >> str;
		m[str] = c;
	}

	cin >> encoded;
	int size = encoded.size();
	int i = 0, j = 1;

	while (i < size) {
		if (m.find(encoded.substr(i, j)) != m.end()) {
			decoded += m[encoded.substr(i, j)];
			i += j, j = 1;
		}
		else {
			j++;
		}
	}
	cout << decoded;

	return 0;
}