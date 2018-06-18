#include <algorithm>
#include <iostream>
using namespace std;

int sort1(int n) {
    int a[4] = {n % 10, (n / 10) % 10, (n / 100) % 10, (n / 1000) % 10};
    sort(a, a + 4);
    return a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
}

int sort2(int n) {
    int a[4] = {n % 10, (n / 10) % 10, (n / 100) % 10, (n / 1000) % 10};
    sort(a, a + 4);
    return a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    while (1) {
        int a = sort1(n);
        int b = sort2(n);
        n = b - a;
        printf("%04d - %04d = %04d\n", b, a, n);
        if (n == 0 || n == 6174)
            break;
    }

    return 0;
}