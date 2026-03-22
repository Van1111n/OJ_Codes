#include <cmath>
#include <iostream>
#define TEST 0

using namespace std;

void prt_points(double* x, double* y, int n) {
    printf("points:\n");
    for (int i = 0; i < n; ++i) {
        printf("%lf, %lf\n", x[i], y[i]);
    }
    printf("\n");
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    double *x = (double*)malloc(n * sizeof(double)), *y = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        int l, r;
        scanf("%d %d", &l, &r);
        --l;--r;
        switch (type) {
            case 1: {
                double a, b;
                scanf("%lf %lf", &a, &b);
                for (int j = l; j <= r; j++) {
                    x[j] += a;
                    y[j] += b;
                }
                if (TEST)
                    prt_points(x, y, n);
                break;
            }
            case 2: {
                double a, b, theta;
                scanf("%lf %lf %lf", &a, &b, &theta);
                for (int j = l; j <= r; j++) {
                    double xp = a + (x[j] - a) * cos(theta) - (y[j] - b) * sin(theta);
                    double yp = b + (x[j] - a) * sin(theta) + (y[j] - b) * cos(theta);
                    x[j] = xp;
                    y[j] = yp;
                }
                if (TEST)
                    prt_points(x, y, n);
                break;
            }
            case 3: {
                double a, b, lamda;
                scanf("%lf %lf %lf", &a, &b, &lamda);
                for (int j = l; j <= r; j++) {
                    double xp = lamda * (x[j] - a) + a;
                    double yp = lamda * (y[j] - b) + b;
                    x[j] = xp;
                    y[j] = yp;
                }
                if (TEST)
                    prt_points(x, y, n);
                break;
            }
            case 4: {
                double theta, b;
                scanf("%lf %lf", &theta, &b);
                double k = tan(theta);
                for (int j = l; j <= r; j++) {
                    double xp = (-k * k * x[j] + x[j] - 2 * k * b + 2 * k * y[j]) / (k * k + 1);
                    double yp = (2 * k * x[j] + k * k * y[j] + 2 * b - y[j]) / (k * k + 1);
                    x[j] = xp;
                    y[j] = yp;
                }
                if (TEST)
                    prt_points(x, y, n);
                break;
            }
            case 5: {
                double theta, b;
                scanf("%lf %lf", &theta, &b);
                double k = tan(theta);
                for (int j = l; j <= r; j++) {
                    double xp = (x[j] - k * b + k * y[j]) / (k * k + 1);
                    double yp = (k * x[j] + k * k * y[j] + b) / (k * k + 1);
                    x[j] = xp;
                    y[j] = yp;
                }
                if (TEST)
                    prt_points(x, y, n);
                break;
            }
            case 6: {
                double gravCenterX = 0, gravCenterY = 0;
                int m = r - l + 1;
                for (int j = l; j <= r; j++) {
                    gravCenterX += x[j];
                    gravCenterY += y[j];
                }
                gravCenterX /= m, gravCenterY /= m;
                printf("%lf %lf\n", gravCenterX, gravCenterY);
                break;
            }
            case 7: {
                double a, b;
                scanf("%lf %lf", &a, &b);
                double ans = 0;
                for (int j = l; j <= r; j++) {
                    ans += (x[j] - a) * (x[j] - a) + (y[j] - b) * (y[j] - b);
                }
                printf("%lf\n", ans);
                break;
            }
        }
    }
}