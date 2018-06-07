#include <iostream>
using namespace std;

const int maxn = 105;
int a[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    m %= n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (i)
            cout << " ";
        cout << a[(i - m + n) % n];
    }
    cout << endl;
    return 0;
}