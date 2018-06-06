#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 105;

bool isKeyNum[maxn];
vector<int> vec;

void Callatz(int n) {
    bool isFirst = true;
    while (n > 1) {
        if (isFirst) {
            isFirst = false;
        } else {
            auto iter = lower_bound(vec.begin(), vec.end(), n);
            if (*iter == n) {
                int idx = distance(vec.begin(), iter);
                isKeyNum[idx] = false;
            }
        }
        if (n % 2) {
            n = (n * 3 + 1) / 2;
        } else {
            n /= 2;
        }
    }
}

int main() {
    // cin.tie(false);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    vec.clear();
    memset(isKeyNum, true, sizeof(isKeyNum));

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        vec.insert(lower_bound(vec.begin(), vec.end(), a), a);
    }

    for (int i : vec)
        Callatz(i);

    bool isFirst = true;
    for (int i = n - 1; i >= 0; --i)
        if (isKeyNum[i]) {
            if (isFirst)
                isFirst = false;
            else
                cout << " ";
            cout << vec[i];
        }
    cout << endl;

    return 0;
}