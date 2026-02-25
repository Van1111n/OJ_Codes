#include <cstdio>
//TODO:
bool isNum(char c){
    if ('0'<=c && c<='9') return true;
    else return false;
}

bool isLetter(char c){
    if ('a'<=c && c<='z') return true;
    else return false;
}

int main(){
    int p1, p2, p3;
    char s[100];
    scanf("%d %d %d", &p1, &p2, &p3);
    scanf("%s",s);
    for (int i=0; s[i]!='\0'; i++){
        if (s[i]=='-'
            && (isNum(s[i - 1]) && isNum(s[i + 1]) || isLetter(s[i - 1]) && isLetter(s[i + 1])) 
            && s[i - 1] < s[i + 1]){
            
        }
        else putchar(s[i]);
    }
}