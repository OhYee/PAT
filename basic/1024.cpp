#include <cmath>
#include <cstdio>
#include<cstring>
const int maxn = 10010;

char s[maxn];
char base[maxn];

/*
    Find the first character c in the string s.
    Arguments:
        s   -   string
        len -   length of s
        c   -   the character to find
    Return:
        The position of the character in the string.
        If cann't find the character, return -1.
*/
int findChar(char *s,int len,char c){
    int pos = -1;
    for(int i=0;i<len;++i){
        if(s[i] == c){
            pos = i;
            break;
        }
    }
    return pos;
}

/*
    Erase the nonnumeric character.
    Arguments:
        s   -   raw string.
        len -   length of s.
    Return:
        Length of the string.
*/
int eraseNonChar(char *s, int len) {
    int pos=0;
    for (int i=0;i<len;++i){
        if(s[i]>='0'&&s[i]<='9')
            s[i-pos] = s[i];
        else
            ++pos;    
    }
    s[len-pos]='\0';
    return len-pos;
}

/*
    String to integer
    Arguments:
        s       -   string
        bpos    -   begin position
        epos    -   end position
    Return:
        The integer
*/
int toInt(char *s, int bpos,int epos){
    int fix = 1;
    int num=0;
    for(int i=bpos;i<epos;++i){
        if (i==bpos && (s[i]=='+'||s[i]=='-')){
            if(s[i]=='-')
                fix = -1;
        }else{
            if(s[i]>='0'&&s[i]<='9')
                num=num*10+s[i]-'0';
        }
    }
    return num*fix;
}

/*
    Get the sub-string
    Arguments:
        dst     -   destination string
        src     -   source string
        bpos    -   begin position
        epos    -   end position
    Return:
        The integer
*/
void subString(char *dst, char *src, int bpos, int epos){
    //memcpy(dst,src+bpos,(epos-bpos)*sizeof(char));
    
    //printf("%s %d %d\n",src,bpos,epos);
    for(int i = 0;i < epos-bpos;++i)
        dst[i] = src[i+bpos];
    dst[epos-bpos]='\0';
    
}

int main() {
    scanf("%s",s);
    int len  = strlen(s);
    int ePos = findChar(s,len,'E');
    bool fix = false;

    subString(base,s,0,ePos);
    fix = (base[0]=='-');
    int baseLen = eraseNonChar(base,strlen(base));
    int exponent = toInt(s,ePos+1,len);
    
    // printf("%c %s %d\n",(fix?'-':'+'),base,exponent);
    
    if(baseLen==1 && base[0]=='0') {
        printf("0");
    } else {
        if(fix)
            printf("-");
        if(exponent<0){
            for(int i=0;i<-exponent;++i){
                printf("0");
                if(i==0)
                    printf(".");
            }
            printf("%s",base);
        }else{
            bool isFirst = true;
            for(int i=0;i<baseLen;++i){
                if(!isFirst || base[i]!='0'){
                    printf("%c",base[i]);
                    isFirst = false;
                }
                if(exponent==i && i!=baseLen-1)
                    printf(".");
            }
            for(int i=0;i<=exponent-baseLen;++i)
                printf("0");
        }
    }
    printf("\n");
    return 0;
}
