#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    int pos = s.size();

    string ans = "";
    for (char c : s) {
        int cnt = c -= '0';
        for (int i = 1; i <= cnt; ++i) {
            if (pos == 3)
                ans += "B";
            if (pos == 2)
                ans += "S";
            if (pos == 1)
                ans += i + '0';
        }
        --pos;
    }
    cout << ans << endl;

    return 0;
}