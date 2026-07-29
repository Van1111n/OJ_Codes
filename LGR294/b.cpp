#include <iostream>

inline int det(int a, int b, int c, int d) {
    return a*d-b*c;
}

int main() {
    int x, y;
    std::cin >> x >> y;
    int ans = 0;
    for (int a=x; a<=y; a++) {
        for (int b=x; b<=y; b++) {
            for (int c=x; c<=y; c++) {
                for (int d=x; d<=y; d++) {
                    if (det(a,b,c,d) == 0) {
                        ++ans;
                    }
                }
            }
        }
    }
    std::cout << ans << std::endl;
}