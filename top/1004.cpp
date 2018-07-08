#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

#define Log(format, ...) // printf(format, ##__VA_ARGS__)

const int maxn = 105;
const int maxL = 1005;
const int INF = (2u << 30) - 1;

struct BeadString {
    static int beadColorType;
    static int colorMap[64];

    int cnt[64];
    int neededBeads;
    int overflow;

    static int getBeadColorValue(char c) {
        int value = 0;
        if (c >= '0' && c <= '9')
            value = c - '0';
        else if (c >= 'a' && c <= 'z')
            value = c - 'a' + 10;
        else
            value = c - 'A' + 10 + 26;
        return value;
    }
    static int getBeadColorIndex(char c) {
        return colorMap[getBeadColorValue(c)];
    }

    static BeadString setBeadColorType(string s) {
        beadColorType = 0;
        memset(colorMap, -1, sizeof(colorMap));

        for (char c : s) {
            int value = getBeadColorValue(c);
            if (colorMap[value] == -1)
                colorMap[value] = beadColorType++;
        }

        return BeadString(s);
    }

    BeadString() {}
    BeadString(string s) {
        neededBeads = overflow = 0;
        memset(cnt, 0, sizeof(cnt));
        for (char c : s) {
            int idx = getBeadColorIndex(c);
            if (idx == -1)
                ++overflow;
            else
                ++cnt[idx], ++neededBeads;
        }
    }

    bool operator<(const BeadString &rhs) const {
        return overflow < rhs.overflow;
    }

    void debug() {
        Log("neededBeads = %d  overflow = %d\n", neededBeads, overflow);
        Log("idx\t");
        for (int i = 0; i < beadColorType; ++i)
            Log("%4d ", i);
        Log("\ncnt\t");
        for (int i = 0; i < beadColorType; ++i)
            Log("%4d ", cnt[i]);
        Log("\n");
    }
};

int BeadString::beadColorType = 0;
int BeadString::colorMap[64];

vector<BeadString> beadString;
int beadStringNumber = 0;

int lastBeads[maxn][64];

int ans = INF;
bool choose[maxn];


int dfs(int t, BeadString need) {
    Log("\ndfs(%d) lastBeads=%d ans=%d\n", t, lastBeads[t][63], ans);
    Log("idx\t");
    for (int i = 0; i < beadStringNumber; ++i)
        Log("%4d ", i);
    Log("\nchoose\t");
    for (int i = 0; i < beadStringNumber; ++i)
        Log("%4d ", choose[i]);
    Log("\n-------\nneed\n------\n");
    need.debug();

    // 找到答案
    if (need.neededBeads == 0 || ans == 0) {
        Log("Get ans\n");
        return ans = min(ans, need.overflow);
    }
    // 找到头，仍然没有答案
    if (t >= beadStringNumber) {
        Log("At end\n");
        return ans;
    }
    // 如果已经不可能比最优解好，剪枝
    if (need.overflow > ans) {
        Log("Cannot get best ans\n");
        return ans;
    }
    // 如果剩下的全部选上，也不能得到所有珠子，剪枝
    if (need.neededBeads > lastBeads[t][63]) {
        Log("No enough beads 0\n");
        return ans;
    }

    for (int i = 0; i < BeadString::beadColorType; ++i) {
        if (need.cnt[i] > lastBeads[t][i]) {
            Log("No enough beads 1\n");
            return ans;
        }
    }

    BeadString &nowBeadString = beadString[t];

    // 不选当前链
    int nowAns = dfs(t + 1, need);

    // 选择当前链
    // 只有当前链有需要的东西时，才尝试选择该链
    bool noNeed = false;

    if (nowBeadString.neededBeads)
        noNeed = false;

    for (int i = 0; noNeed == false && i < BeadString::beadColorType; ++i) {
        if (need.cnt[i] && nowBeadString.cnt[i])
            noNeed = false;
    }

    if (!noNeed) {
        choose[t] = true;
        Log("-------\nnowBeadString %d\n------\n", t);
        nowBeadString.debug();

        for (int i = 0; i < BeadString::beadColorType; ++i) {
            if (need.cnt[i] >= nowBeadString.cnt[i]) {
                need.cnt[i] -= nowBeadString.cnt[i];
                need.neededBeads -= nowBeadString.cnt[i];
            } else {
                need.neededBeads -= need.cnt[i];
                need.overflow += nowBeadString.cnt[i] - need.cnt[i];
                need.cnt[i] = 0;
            }
        }
        need.overflow += nowBeadString.overflow;

        nowAns = min(dfs(t + 1, need), nowAns);

        choose[t] = false;
    }

    return nowAns;
}

char s[maxL];
int main() {
    beadStringNumber = 0;

    scanf("%s%d", s, &beadStringNumber);
    BeadString request = BeadString::setBeadColorType(string(s));

    string compoud = "";
    for (int i = 0; i < beadStringNumber; ++i) {
        scanf("%s", s);
        beadString.push_back(string(s));
    }
    sort(beadString.begin(), beadString.end());

    // 预处理
    int missing = 0; // 缺少的珠子个数
    memset(lastBeads, 0, sizeof(lastBeads));
    for (int i = beadStringNumber - 1; i >= 0; --i) {
        // 记录该串后面所有串需要的珠子的总数
        lastBeads[i][63] = lastBeads[i + 1][63] + beadString[i].neededBeads;

        bool match = true;
        for (int j = 0; j < BeadString::beadColorType; ++j) {
            // 具体到每种颜色的数目
            lastBeads[i][j] = lastBeads[i + 1][j] + beadString[i].cnt[j];
            if (request.cnt[j] && (beadString[i].cnt[j] != request.cnt[j]))
                match = false; // 该串不能刚好满足要求
            if (i == 0 && request.cnt[j] > lastBeads[0][j])
                missing += request.cnt[j] - lastBeads[0][j];
        }
        if (match && beadString[i].overflow == 0)
            ans = 0; // 存在和要求完全相同的串
    }

    memset(choose, 0, sizeof(choose));

    if (missing) {
        printf("No %d\n", missing);
    } else {
        printf("Yes %d\n", dfs(0, request));
    }
    return 0;
}