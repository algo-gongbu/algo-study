#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long T;
    int n, m;
    cin >> T;
    cin >> n;
    vector<int> A(n);
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }
    cin >> m;
    vector<int> B(m);
    for (int i=0; i<m; i++) {
        cin >> B[i];
    }

    vector<long long> sumA;
    vector<long long> sumB;
    for (int i=0; i<n; i++) {
        long long curr = 0;
        for (int j=i; j<n; j++) {
            curr += A[j];
            sumA.push_back(curr);
        }
    }
    for (int i=0; i<m; i++) {
        long long curr = 0;
        for (int j=i; j<m; j++) {
            curr += B[j];
            sumB.push_back(curr);
        }
    }
    
    sort(sumA.begin(), sumA.end());
    sort(sumB.begin(), sumB.end());

    int left = 0, right = sumB.size()-1;
    long long ans = 0;
    while (left < sumA.size() && right >= 0) {
        long long curr = sumA[left] + sumB[right];
        if (curr == T) {
            long long tarA = sumA[left];
            long long tarB = sumB[right];
            long long countA = 0;
            long long countB = 0;

            while (left < sumA.size() && sumA[left] == tarA) {
                countA++;
                left++;
            }
            while (right >=0 && sumB[right] == tarB) {
                countB++;
                right--;
            }
            ans += countA * countB;
        }
        else if (curr < T) left++;
        else right--;
    }

    cout << ans << "\n";

    return 0;
}