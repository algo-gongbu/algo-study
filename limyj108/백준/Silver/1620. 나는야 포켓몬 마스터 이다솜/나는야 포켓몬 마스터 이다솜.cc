#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	string name, temp;
	map<int, string> book;
	map<string, int> reverse_book;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> name;
		book[i] = name;
		reverse_book[name] = i;
	}

	for (int i = 0; i < M; i++) {
		cin >> temp;
		if (('A' <= temp[0] && temp[0] <= 'Z') || ('a' <= temp[0] && temp[0] <= 'z')) {
			cout << reverse_book[temp] << "\n";
		}
		else {
			cout << book[stoi(temp)] << "\n";
		}
	}

	return 0;
}