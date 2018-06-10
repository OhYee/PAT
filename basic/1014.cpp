#include <cmath>
#include <iostream>
#include <string>
using namespace std;

const char weekday[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    int len1 = min(a.size(), b.size());
    int apos = -1;
    int bpos = -1;

    for (int i = 0; i < len1; ++i) {
        if (apos == -1) {
            if (a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G') {
                apos = i;
            }
        } else {
            if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') ||
                                 (a[i] >= '0' && a[i] <= '9'))) {
                if (i != apos) {
                    bpos = i;
                    break;
                }
            }
        }
    }

    int len2 = min(c.size(), d.size());
    int cpos = -1;
    for (int i = 0; i < len2; ++i) {
        if (c[i] == d[i] && ((c[i] >= 'A' && c[i] <= 'Z')||(c[i] >= 'a' && c[i] <= 'z'))) {
            cpos = i;
            break;
        }
    }

    printf("%s %02d:%02d\n", weekday[a[apos] - 'A'],
           (a[bpos] <= '9' ? a[bpos] - '0' : a[bpos] - 'A' + 10), cpos);

    return 0;
}