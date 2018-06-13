#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    string a, b;
    char ad, bd;
    long long ac = 0, bc = 0;

    cin >> a >> ad >> b >> bd;
    for (char c : a) {
        if (c == ad)
            ac = ac * 10 + ad - '0';
    }
    for (char c : b) {
        if (c == bd)
            bc = bc * 10 + bd - '0';
    }
    cout << ac + bc << endl;
    return 0;
}