#include <iostream>
#include <string.h>
#include <ctype.h>
#include <limits.h>

void trans_to_lower(char s[]){
    for (int i=0; i<strlen(s); i++){
        if (isupper(s[i])) {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return;
}

int max(int a, int b) {
    return (a > b ? a : b); 
}

int main(){
    char target[65536], current[65536];
    int curPos=0, minPos=INT_MAX;
    int count=0;
    bool found, end;
    char c;

    scanf("%s\n", target);
    trans_to_lower(target);
    end = false;
    while (!end){
        int i=0;
        while (1){
            c=getchar();
            if (c==' ') break;
            if (c=='\n') {
                end = true;
                break;
            }
            current[i]=c;
            i++;
        }
        current[i] = '\0';
        trans_to_lower(current);
        found = true;
        for (int i=0; i < max(strlen(target), strlen(current)); i++){
            if (current[i] != target[i]) {
                found = false;
            }
        }
        if (found){
            count++;
            minPos = curPos < minPos ? curPos : minPos;
        }
        if (!end) curPos += strlen(current) + 1;
    }
    if (count) printf("%d %d", count, minPos);
    else printf("-1");
    return 0;

}