#include <algorithm>
#include <cstdio>
const int maxn = 105;

struct Node {
    char name[maxn];
    char id[maxn];
    int score;
    void input() { scanf("%s%s%d", name, id, &score); }
    void print() { printf("%s %s\n", name, id); }
    bool operator<(const Node &rhs) const { return score > rhs.score; }
};
Node student[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        student[i].input();
    std::sort(student, student + n);
    student[0].print();
    student[n-1].print();
    return 0;
}