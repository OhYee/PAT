#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);
    string s;
    cin >> s;
    int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (char c : s)
        ++cnt[c - '0'];
    for (int i = 0; i < 10; ++i)
        if (cnt[i] != 0)
            cout << i << ":" << cnt[i] << endl;
    return 0;
}