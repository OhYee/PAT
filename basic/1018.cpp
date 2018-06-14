#include <iostream>
using namespace std;

int getLevel(char a) {
    if (a == 'C')
        return 2;
    if (a == 'J')
        return 1;
    if (a == 'B')
        return 0;
    return -1;
}

int judge(char a, char b) {
    int aLevel = getLevel(a);
    int bLevel = getLevel(b);
    if (aLevel == bLevel)
        return 0;
    else if (aLevel - bLevel == 1 || aLevel - bLevel == -2)
        return 1;
    else
        return -1;
}

int score[2][3] = {{0, 0, 0}, {0, 0, 0}};
int cnt[2][3] = {{0, 0, 0}, {0, 0, 0}};

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char a, b;
        cin >> a >> b;
        int nowScore = judge(a, b);
        ++score[0][1 - nowScore];
        ++score[1][1 + nowScore];
        if (nowScore == 1)
            ++cnt[0][getLevel(a)];
        if (nowScore == -1)
            ++cnt[1][getLevel(b)];
    }

    // cout << cnt[0][0] << " " << cnt[0][1] << " " << cnt[0][2] << endl;
    // cout << cnt[1][0] << " " << cnt[1][1] << " " << cnt[1][2] << endl;

    int maxValue = 0;
    for (int i = 0; i < 3; ++i)
        maxValue = maxValue > cnt[0][i] ? maxValue : cnt[0][i];
    char aMax = maxValue == cnt[0][0] ? 'B' : maxValue == cnt[0][2] ? 'C' : 'J';

    maxValue = 0;
    for (int i = 0; i < 3; ++i)
        maxValue = maxValue > cnt[1][i] ? maxValue : cnt[1][i];
    char bMax = maxValue == cnt[1][0] ? 'B' : maxValue == cnt[1][2] ? 'C' : 'J';

    cout << score[0][0] << " " << score[0][1] << " " << score[0][2] << endl;
    cout << score[1][0] << " " << score[1][1] << " " << score[1][2] << endl;
    cout << aMax << " " << bMax << endl;

    return 0;
}