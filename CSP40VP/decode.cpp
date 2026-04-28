#include <algorithm>
#include <iostream>
#define ZMAX 400
#define KMAX 300010
using namespace std;

int main() {
    int z;
    scanf("%d", &z);
    char picture[ZMAX][ZMAX];
    for (int i = 0; i < z; i++) {
        scanf("%s", picture[i]);
    }
    int kLen;
    scanf("%d", &kLen);
    int key[KMAX];
    for (int i = 0; i < kLen; i++) {
        scanf("%d", &key[i]);
    }
    int cur = kLen - 6;
    while (cur > 0) {
        int op = key[cur++];
        if (op == 2) {  // 反转逆变换
            int u = --key[cur++];
            int d = --key[cur++];
            int l = --key[cur++];
            int r = --key[cur++];
            int o = key[cur++];
            if (o == 1) {  // 上下翻转
                for (int i = 0; i <= (d - u) / 2; i++) {
                    for (int j = l; j <= r; j++) {
                        swap(picture[u + i][j], picture[d - i][j]);
                    }
                }
            } else {  // 左右翻转
                for (int i = u; i <= d; i++) {
                    for (int j = 0; j <= (r - l) / 2; j++) {
                        swap(picture[i][l + j], picture[i][r - j]);
                    }
                }
            }
        } else {  // 旋转逆变换
            int u = --key[cur++];
            int v = --key[cur++];
            int l = key[cur++];
            int d = key[cur++] % 360;
            int r = key[cur++] % 4;
            // 先对整张图顺时针旋转90度r次
            char temp[ZMAX][ZMAX];
            if (r == 3) {
                for (int i = 0; i < z; i++) {
                    for (int j = 0; j < z; j++) {
                        temp[z - 1 - j][i] = picture[i][j];
                    }
                }
            } else if (r == 2) {
                for (int i = 0; i < z; i++) {
                    for (int j = 0; j < z; j++) {
                        temp[z - 1 - i][z - 1 - j] = picture[i][j];
                    }
                }
            } else if (r == 1) {
                for (int i = 0; i < z; i++) {
                    for (int j = 0; j < z; j++) {
                        temp[j][z - i - 1] = picture[i][j];
                    }
                }
            }
            for (int i = 0; i < z; i++) {
                for (int j = 0; j < z; j++) {
                    picture[i][j] = temp[i][j];
                }
            }
            // 再对部分图片逆时针旋转d度
            char sub[l][l];
            if (d == 90) {
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < l; j++) {
                        sub[l - 1 - j][i] = picture[u + i][v + j];
                    }
                }
            } else if (d == 180) {
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < l; j++) {
                        sub[l - 1 - i][l - 1 - j] = picture[u + i][v + j];
                    }
                }
            } else if (d == 270) {
                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < l; j++) {
                        sub[j][l - 1 - i] = picture[u + i][v + j];
                    }
                }
            }
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < l; j++) {
                    picture[u + i][v + j] = sub[i][j];
                }
            }
        }
        cur -= 12;
    }
    int x = 0, y = 0;
    while (picture[x][0] != '?')
        ++x;
    while (picture[0][y] != '?')
        ++y;
    printf("%d %d\n", x, y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            putchar(picture[i][j]);
        }
        putchar('\n');
    }
    return 0;
}