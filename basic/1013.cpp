#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 110005;

int prime[maxn];
bool isPrime[maxn];
int pos;

void listPrime(int maxNum) {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    pos = 0;
    for (int i = 2; i <= maxNum; ++i) {
        if (isPrime[i])
            prime[pos++] = i;
        for (int j = 0; j < pos && i * prime[j] <= maxNum; ++j) {
            isPrime[i * prime[j]] = false;
            if (!(i % prime[j]))
                break;
        }
    }
}

int ans[maxn];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    listPrime(110000);

    bool isFirst = true;
    int cnt = 0;
    for (int i = n; i <= m; ++i) {
        if (cnt == 10) {
            cout << endl;
            cnt = 0;
            isFirst = true;
        }
        if (isFirst)
            isFirst = false;
        else
            cout << " ";
        cnt++;
        cout << prime[i - 1];
    }
    cout << endl;
    return 0;
}