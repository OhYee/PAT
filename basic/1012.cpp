#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

const double eps = 1e-12;
int sgn(const double &x) {
    if (fabs(x) < eps)
        return 0;
    return x > 0 ? 1 : -1;
}
int double_round(double num) { return sgn(num) > 0 ? num + 0.5 : num - 0.5; }

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    int A[5] = {0, 0, 0, 0, -90000};
    bool has[5] = {0, 0, 0, 0, 0};
    int flag = 1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a;
        b = a % 5;

        if (b == 0 && a % 2 == 0) {
            has[0] = 1;
            A[0] += a;
        }
        if (b == 1) {
            has[1] = 1;
            A[1] += flag * a;
            flag *= -1;
        }
        if (b == 2) {
            has[2] = 1;
            A[2]++;
        }
        if (b == 3) {
            has[3] = 1;

            A[3] += a;
            cnt++;
        }
        if (b == 4) {
            has[4] = 1;
            A[4] = A[4] > a ? A[4] : a;
        }
    }
    bool isFirst = true;
    for (int i = 0; i < 5; ++i) {
        if (isFirst) {
            isFirst = false;
        } else {
            cout << " ";
        }
        if (has[i])
            if (i == 3)
                cout << fixed << setprecision(1)
                     << (double)double_round((double)A[3] / cnt * 10) / 10;
            else
                cout << A[i];
        else
            cout << "N";
    }
    cout << endl;
    return 0;
}