#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

double get_distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    if ((yb - ya) * (xc - xb) == (yc - yb) * (xb - xa)) {
        cout << "-1.0\n";
        return 0;
    }

    double ab = get_distance(xa, ya, xb, yb);
    double bc = get_distance(xb, yb, xc, yc);
    double ca = get_distance(xc, yc, xa, ya);

    double max_side = max({ab, bc, ca});
    double min_side = min({ab, bc, ca});

    double max_diff = 2.0 * (max_side - min_side);

    cout << fixed << setprecision(10) << max_diff << "\n";

    return 0;
}