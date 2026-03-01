#include <iostream>

using namespace std;

// calc a/b=c...r
int main() {
    int a[5001], c[5001];
    int b;
    char temp;
    int length=0;
    // a[0]表示最高位，以此类推
    while(1){
        scanf("%c", &temp);
        if (temp=='\n') break;
        else a[length]=temp-'0';
        length++;
    }
    a[length] = -1;
    c[length] = -1;
    scanf("%d", &b);
    int r = 0, d = 0;
    // 每步中，d是除数，r是余数
    for (int i = 0; i < length; i++) {
        d = 10 * r + a[i];
        c[i] = d / b;
        r = d % b;
    }
    // 跳过c的前导0再输出
    int i;
    for (i = 0; i < length; i++) {
        if (c[i] != 0) break;
    }
    if (i==length) printf("0");
    for (; i < length; i++) {
        printf("%d", c[i]);
    }
    return 0;
}