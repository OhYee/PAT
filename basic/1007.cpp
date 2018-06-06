#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e5 + 5;

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

    int n;
    cin >> n;
    listPrime(n);

    int cnt = 0;
    for (int i = 1; prime[i] <= n && i < pos; ++i) {
        if (prime[i] - prime[i - 1] == 2)
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}