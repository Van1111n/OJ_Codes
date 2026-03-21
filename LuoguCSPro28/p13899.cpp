#include <cmath>
#include <iostream>

using namespace std;

const double PI = acos(-1);

void prt_matrix(int m[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void prt_matrix_lf(double m[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%lf ", m[i][j]);
        }
        printf("\n");
    }
}

double alpha(int u) {
    if (u == 0) return sqrt(0.5);
    else return 1.0;
}

int main() {
    //printf("%lf", PI);
    int q[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%d", &q[i][j]);
        }
    }
    int m[8][8] = {0};
    int n, t, scan[64];
    scanf("%d", &n);
    scanf("%d", &t);
    for (int i = 0; i < n; i++) {
        scanf("%d", &scan[i]);
    }
    //fill
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        //printf("m[%d][%d] = %d\n", x, y, scan[i]);
        m[x][y] = scan[i];
        if ((x + y) % 2 == 0) {
            if (x == 0) {
                ++y;
            } else if(y == 7) {
                ++x;
            } else {
                --x;
                ++y;
            }
        } else {
            if (y == 0 && x != 7) {
                ++x;
            } else if(x == 7) {
                ++y;
            } else {
                ++x;
                --y;
            }
        }
    }
    if (t == 0) prt_matrix(m);
    //quantify
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m[i][j] *= q[i][j];
        }
    }
    if (t == 1) prt_matrix(m);
    //Discrete cosine trans
    double mp[8][8] = {0};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for(int u = 0; u < 8; u++) {
                for (int v = 0; v < 8; v++) {
                    mp[i][j] += alpha(u) * alpha(v) * m[u][v] * cos(PI / 8 * (i + 0.5) * u) * cos(PI / 8 * (j + 0.5) * v);
                }
            }
            mp[i][j] /= 4.0;
        }
    }
    //final decode
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            mp[i][j] += 128.0;
            m[i][j] = (int)(mp[i][j] + 0.5);
            m[i][j] = m[i][j] > 255 ? 255 : m[i][j];
            m[i][j] = m[i][j] < 0 ? 0 : m[i][j];
        }
    }
    if(t == 2) prt_matrix(m);
    return 0;
}