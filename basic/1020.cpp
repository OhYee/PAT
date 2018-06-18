#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 1005;
const double eps = 1e-9;

struct Node {
    double w, p;
    double getPrice() const { return p / w; }
    bool operator<(const Node &rhs) const {
        return getPrice() > rhs.getPrice();
    }
};
Node goods[maxn];

int sgn(double n) { return fabs(n) < eps ? 0 : n > 0 ? 1 : -1; }
int double_round(double n) { return sgn(n) > 0 ? n + 0.5 : n - 0.5; }

int main() {
    int n, D;
    scanf("%d%d", &n, &D);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &goods[i].w);
    for (int i = 0; i < n; ++i)
        scanf("%lf", &goods[i].p);
    sort(goods, goods + n);

    double ans = 0.0;
    for (int i = 0; i < n && D > 0; ++i) {
        if (D >= goods[i].w) {
            ans += goods[i].p;
            D -= goods[i].w;
        } else {
            ans += goods[i].getPrice() * D;
            D = 0;
        }
    }
    printf("%.2f\n", (double)double_round(ans * 100) / 100);
    return 0;
}