#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string toD(int num, int D) {
    string ans = "";
    do {
        ans += (num % D)+'0';
        num /= D;
    } while (num != 0);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
    int A, B, D;
    cin >> A >> B >> D;
    cout << toD(A + B, D) << endl;
    return 0;
}