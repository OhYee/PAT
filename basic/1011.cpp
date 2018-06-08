#include <iostream>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i << ": " << (a + b > c ? "true" : "false") << endl;
    }
    return 0;
}