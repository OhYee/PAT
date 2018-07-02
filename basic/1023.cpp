#include <iostream>
#include <string>
using namespace std;
int cnt[10];
int main() {
    bool isFirst = true;
    string ans = "";
    for (int i = 0; i < 10; ++i) {
        cin >> cnt[i];
        if (i && cnt[i] && isFirst) {
            ans += i+'0';
            --cnt[i];
            isFirst = false;
        }
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < cnt[i]; ++j)
            ans += i+'0';
    }
    cout<<ans<<endl;
    return 0;
}