#include <iostream>

using namespace std;

int main() {
    int z, c, xp, yp, count = 0;
    scanf("%d %d %d", &xp, &yp, &z);
    for (int x0 = 10; x0 <= 99; x0++) {
        for (int y0 = 10; y0 <= 99; y0++) {
            c = 0;
            int x = x0;
            int y = y0;
            while (c < z) {
                if ((x + y) % 2 == 1) {
                    x -= y % x;
                } else {
                    y -= x % y;
                }
                if (x < c)
                    x += y / 2 + 1;
                if (y < c)
                    y += x / 2 + 1;
                ++c;
            }
            if (x == xp && y == yp)
                ++count;
        }
    }
    printf("%d", count);
}