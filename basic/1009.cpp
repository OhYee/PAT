#include <cstring>
#include <iostream>
const int maxn = 105;
char s[maxn];
char stackString[maxn];
int stackPos;
char outputString[maxn];
int outputPos;

void output() {
    while (stackPos != 0)
        outputString[outputPos++] = stackString[--stackPos];
    outputString[outputPos++] = ' ';
}
int main() {
    scanf("%[^\n]", s);
    int len = strlen(s);

    stackPos = 0;
    outputPos = 0;

    for (int i = len - 1; i >= 0; --i) {
        if (s[i] == ' ') {
            output();
        } else {
            stackString[stackPos++] = s[i];
        }
    }
    output();
    outputString[--outputPos]= '\0';

    printf("%s\n", outputString);
    return 0;
}