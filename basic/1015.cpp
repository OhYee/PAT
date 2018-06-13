#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e5 + 5;
int n, L, H;

struct Node {
    int id, d, c;
    Node() {}
    Node(int _id, int _d, int _c) : id(_id), d(_d), c(_c) {}

    static int getGrade(const Node stu) {
        if (stu.d >= H && stu.c >= H)
            return 4;
        else if (stu.d >= H && stu.c < H)
            return 3;
        else if (stu.d < H && stu.c < H && stu.d >= stu.c)
            return 2;
        else
            return 1;
    }
    bool operator<(const Node &rhs) const {
        const Node stu1 = *this;
        const Node stu2 = rhs;
        int gstu1 = Node::getGrade(stu1);
        int gstu2 = Node::getGrade(stu2);
        int ret = 0;
        if (gstu1 == gstu2)
            if ((stu1.d + stu1.c) == (stu2.d + stu2.c))
                if (stu1.d == stu2.d)
                    ret = stu2.id - stu1.id;
                else
                    ret = stu1.d - stu2.d;
            else
                ret = (stu1.d + stu1.c) - (stu2.d + stu2.c);
        else
            ret = gstu1 - gstu2;
        return ret > 0 ? true : false;
    }
};

Node stus[maxn];
int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    cin >> n >> L >> H;

    int m = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b >= L && c >= L)
            stus[m++] = Node(a, b, c);
    }

    sort(stus, stus + m);

    printf("%d\n", m);
    for (int i = 0; i < m; ++i)
        printf("%d %d %d\n", stus[i].id, stus[i].d, stus[i].c);

    return 0;
}
