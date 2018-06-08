#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int a, n;
    bool isFirst = true;
    while (cin >> a >> n) {
        if (n != 0) {
            if (isFirst) {
                isFirst = false;
            } else {
                cout << " ";
            }
            cout << a * n << " " << n - 1;
        }
    }
    if (isFirst)
        cout << "0 0";
    cout << endl;
    return 0;
}