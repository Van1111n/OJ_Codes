#include <iostream>
#include <string>

using namespace std;

// calc a/b=c...r
int main() {
    int a[5005], c[5005];
    int b;
    string s;
    int length = 0;
    // a[0]表示最高位，以此类推
    cin >> s;
    scanf("%d", &b);
    for (int i = 0; i < s.size(); i++) {
        a[i] = s.at(i) - '0';
    }
    length = s.length();
    a[length] = c[length] = -1;
    long long r = 0, d = 0;
    // 每步中，d是除数，r是余数
    for (int i = 0; i < length; i++) {
        d = 10 * r + a[i];
        c[i] = d / b;
        r = d % b;
    }
    // 跳过c的前导0再输出
    int i;
    for (i = 0; i < length; i++) {
        if (c[i] != 0)
            break;
    }
    if (i == length)
        printf("0");
    for (; i < length; i++) {
        printf("%d", c[i]);
    }
    return 0;
}