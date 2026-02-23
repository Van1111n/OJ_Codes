#include <iostream>
#include <string>

int main(){
    int n;
    char s[101];
    bool canAdd=0;
    int count=0;
    scanf("%d", &n);
    scanf("%s", s+1);

    for (int i=1; i<=n; i++){
        if (s[i]=='V' && s[i+1] == 'K') {
            count++;
        }
    }
    for (int i=1; i<=n; i++){
        if ((s[i - 1] == 'V' && s[i] == 'V' && s[i + 1] != 'K') ||
            (s[i - 1] != 'V' && s[i] == 'K' && s[i + 1] == 'K')) {
            canAdd = 1;
        }
    }
    printf("%d", count+canAdd);
    return 0;
}