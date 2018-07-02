#include <algorithm>
#include <cstdio>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

struct Node {
    int u, v, w;
    Node(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
    bool operator<(const Node &rhs) const { return w < rhs.w; }
};

const int maxn = 505;
int ans[maxn];
Node edge[maxn * maxn];
int edgePos;

void addEdge(Node e) {
    edge[edgePos++] = e;
    Log("addEdge %d -> %d cost %d\n", e.u, e.v, e.w);
}

int f[maxn];
int ufs(int x) { return f[x] == x ? x : f[x] = ufs(f[x]); }
int Kruskal(int n, int m, int d) {
    int cost = 0;
    for (int i = 0; i <= n; ++i)
        f[i] = i;

    for (int i = 0; i < m; ++i) {
        int u = edge[i].u, v = edge[i].v;
        int x = ufs(u), y = ufs(v);
        Log("\t\t%d(%d) %d(%d)\n", u, x, v, y);
        if (u != d && v != d && x != y) { //　不连接被占领的城市
            Log("\t\tconnect %d -> %d cost %d\n", u, v, edge[i].w);
            f[x] = y;
            cost += edge[i].w;
        }
    }
    int root = 1 == d ? ufs(2) : ufs(1);
    for (int i = 1; i <= n; ++i) {
        if (i != d && ufs(i) != root)
            cost = -1; // 无法连通
    }
    return cost;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    edgePos = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w, s;
        scanf("%d%d%d%d", &u, &v, &w, &s);
        addEdge(Node(u, v, s ? 0 : w));
    }
    sort(edge, edge + m);

    int ansPos = 0, maxCost = 0;
    for (int i = 1; i <= n; ++i) {
        int cost = Kruskal(n, m, i);
        Log("Test %d cost %d\n", i, cost);
        if (maxCost != -1 && (cost > maxCost || cost == -1)) {
            maxCost = cost;
            ansPos = 0;
            ans[ansPos++] = i;
            Log("\tmax value update.\n");
        } else if (cost == maxCost) {
            ans[ansPos++] = i;
            Log("\tadd to ans.\n");
        }
    }

    if (maxCost == 0) {
        printf("0");
    } else {
        for (int i = 0; i < ansPos; ++i) {
            if (i)
                printf(" ");
            printf("%d", ans[i]);
        }
    }
    printf("\n");

    return 0;
}