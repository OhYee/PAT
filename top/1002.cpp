#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

struct Node {
    int p, l, d;
    Node(int _p = 0, int _l = 0, int _d = 0) : p(_p), l(_l), d(_d) {}
    void read() {
        scanf("%d%d%d", &p, &l, &d);
        Log("read %d %d %d\n", p, l, d);
    }
    bool operator<(const Node &rhs) const {
        if (d == rhs.d)
            return l < rhs.l;
        return d < rhs.d;
    }
};

const int maxn = 55;

Node projects[maxn];

int main() {
    int n;
    scanf("%d", &n);

    int maxd = 0;
    for (int i = 1; i <= n; ++i) {
        projects[i].read();
        maxd = max(maxd, projects[i].d);
    }
    Log("maxd %d\n", maxd);

    int **dp = new int *[n + 1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int[maxd + 1];
        memset(dp[i], 0, sizeof(int) * (maxd + 1));
    }

    sort(projects + 1, projects + 1 + n);

    int maxProfit = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= maxd; ++j) {
            dp[i][j] = dp[i - 1][j]; // 不选
            Node pro = projects[i];
            if (j - pro.l >= 0 && j <= pro.d)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - pro.l] + pro.p); // 选
            maxProfit = max(maxProfit, dp[i][j]);
            Log("dp[%d][%d] = %d\t(%d,%d,%d)\n", i, j, dp[i][j], pro.p, pro.l,
                pro.d);
        }
    }

    printf("%d\n", maxProfit);

    for (int i = 0; i <= n; ++i)
        delete[] dp[i];
    delete[] dp;

    return 0;
}