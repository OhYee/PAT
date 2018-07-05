#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#include <vector>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

map<string, int> hashTable;
map<int, string> unHashTable;

int makeHash(char t[4]) {
    static int idx = 0;
    if (idx == 0) {
        hashTable.clear();
        unHashTable.clear();
    }
    string s = string(t);
    if (hashTable.count(s) == 0) {
        hashTable.insert(make_pair(s, idx));
        unHashTable.insert(make_pair(idx, s));
        ++idx;
    }
    int hashCode = hashTable.find(s)->second;
    Log("%s ---> %d\n", s.c_str(), hashCode);
    return hashCode;
}
string unHash(int idx) {
    auto iter = unHashTable.find(idx);
    if (iter == unHashTable.end())
        return "";
    return iter->second;
}

class maxFlow {
    struct Edge {
        int cap, flow;
        Edge(int _cap = 0, int _flow = 0) : cap(_cap), flow(_flow) {}
    };
    static const int INF = 0x7FFFFFFF;
    static const bool DEBUG = false;
    int s, v, n;

    Edge **edges;
    int *dis, *num, *pre, *cur;

  public:
    void addEdge(int from, int to, int cap) {
        Log("%d -> %d cap = %d\n", from, to, cap);
        edges[from][to].cap += cap;
    }

    int ISAP() {
        bfs();
        layerCalc();
        return dfs();
    }
    maxFlow(int s, int v, int n) {
        this->s = s;
        this->v = v;
        this->n = n;

        Log("init %d -> %d  n = %d\n", s, v, n);

        edges = new Edge *[n];
        for (int i = 0; i < n; ++i) {
            edges[i] = new Edge[n];
            memset(edges[i], 0, sizeof(Edge) * n);
        }

        dis = new int[n + 5];
        num = new int[n + 5];
        pre = new int[n + 5];
        cur = new int[n + 5];
    }
    ~maxFlow() {
        for (int i = 0; i < n; ++i)
            delete[] edges[i];
        delete[] edges;

        delete[] dis;
        delete[] num;
        delete[] pre;
        delete[] cur;
    }

  private:
    queue<int> Q;

    void bfs() {
        while (!Q.empty())
            Q.pop();
        memset(dis, 0, sizeof(int) * (n + 5));
        Q.push(v);
        dis[v] = 1;
        while (!Q.empty()) {
            int t = Q.front();
            Q.pop();
            for (int i = 0; i < n; ++i) {
                Edge &e = edges[i][t];
                if (e.cap > e.flow && !dis[i]) {
                    dis[i] = dis[t] + 1;
                    Q.push(i);
                }
            }
        }
    }

    void layerCalc() {
        memset(num, 0, sizeof(int) * (n + 5));
        for (int i = 0; i < n; ++i)
            ++num[dis[i]];
    }

    int Augumemt() {
        int t = v, delta = INF;
        while (t != s) {
            int &lastNode = pre[t];
            Edge &e = edges[lastNode][t];
            delta = min(delta, e.cap - e.flow);
            t = lastNode;
        }
        t = v;
        while (t != s) {
            int &lastNode = pre[t];
            Edge &e = edges[lastNode][t];
            Edge &e2 = edges[t][lastNode];
            e.flow += delta;
            e2.flow -= delta;
            t = lastNode;
        }
        return delta;
    }

    int dfs() {
        memset(pre, 0, sizeof(int) * (n + 5));
        memset(cur, 0, sizeof(int) * (n + 5));

        int flow = 0;
        int t = s;

        while (dis[s] <= n) {
            if (DEBUG)
                test(t);

            if (t == v) {
                flow += Augumemt();
                t = s;
                Log("At the destnation flow = %d\n", flow);
            }

            int finish = true;
            for (int i = cur[t]; i < n; ++i) {
                Edge &e = edges[t][i];
                if (e.cap > e.flow && dis[t] == dis[i] + 1) {
                    finish = false;
                    pre[i] = t;
                    cur[t] = i;
                    t = i;
                    break;
                }
            }

            if (finish) {
                Log("finish\n");
                int m = n;
                for (int i = 0; i < n; i++) {
                    Edge &e = edges[t][i];
                    if (e.cap > e.flow)
                        m = min(m, dis[i]);
                }
                if (--num[dis[t]] == 0)
                    break;
                ++num[dis[t] = m + 1];
                cur[t] = 0;
                if (t != s)
                    t = pre[t];
            }
        }
        return flow;
    }

    void test(int t) {
        Log("At %d\n", t);
        Log("idx:\t");
        for (int i = 0; i < n; ++i)
            Log("%4d ", i);
        Log("\n");
        disTest();
        preTest();
        numTest();
        curTest();
        edgeTest();
        Log("\n\n");
    }
    void disTest() {
        Log("dis:\t");
        for (int i = 0; i <= n; ++i)
            Log("%4d ", dis[i]);
        Log("\n");
    }

    void preTest() {
        Log("pre:\t");
        for (int i = 0; i < n; ++i)
            Log("%4d ", pre[i]);
        Log("\n");
    }

    void numTest() {
        Log("num:\t");
        for (int i = 0; i <= n; ++i)
            Log("%4d ", num[i]);
        Log("\n");
    }
    void curTest() {
        Log("cur:\t");
        for (int i = 0; i < n; ++i)
            Log("%4d ", cur[i]);
        Log("\n");
    }

    void edgeTest() {
        Log("\t");
        for (int i = 0; i < n; ++i)
            Log("%6d    ", i);
        Log("\n");
        for (int i = 0; i < n; ++i) {
            Log("%d\t", i);
            for (int j = 0; j < n; ++j) {
                Log("(%3d,%3d) ", edges[i][j].cap, edges[i][j].flow);
            }
            Log("\n");
        }
    }
};

const int maxn = 505;
struct Node {
    int from, to, cap;
    Node(int _from, int _to, int _cap) : from(_from), to(_to), cap(_cap) {}
};
vector<Node> vec;

int main() {
    int n;
    char a[4], b[4];
    scanf("%s%s%d", a, b, &n);
    int s = makeHash(a), v = makeHash(b);
    vec.clear();
    for (int i = 0; i < n; ++i) {
        int cap;
        scanf("%s%s%d", a, b, &cap);
        int from = makeHash(a), to = makeHash(b);
        vec.push_back(Node(from, to, cap));
    }

    maxFlow ans = maxFlow(s, v, hashTable.size());
    for (auto it = vec.begin(); it != vec.end(); ++it)
        ans.addEdge(it->from, it->to, it->cap);

    printf("%d\n", ans.ISAP());

    return 0;
}