    #include <iostream>
    #include <climits>
    #include <queue>
    #include <string>
    #include <algorithm>

    using namespace std;

    int n, m, h, maximum = INT_MIN, minimum = INT_MAX;
    int arr[1000];
    int res[1000];
    void f() {
        
    }

    int main() {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            
            maximum = 0;
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i]) {
                    if (maximum < res[j]) maximum = res[j];
                }
            }
            res[i] = maximum + 1;
        }

        maximum = 0;
        for (int i = 0; i < n; i++) {
            if (maximum < res[i]) maximum = res[i];
        }

        cout << maximum << "\n";
        return 0;
    }