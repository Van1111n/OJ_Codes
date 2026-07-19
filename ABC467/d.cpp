#include <cmath>
#include <iostream>

#define int unsigned long long

struct Point {
    int x;
    int y;
};

signed main() {
    int t;
    Point p, q, r, s;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y >> s.x >> s.y;
        if ((q.y-p.y)*(r.x-s.x)==(r.y-s.y)*(q.x-q.x)) {
            std::cout << "No" << std::endl;
        } else {
            std::cout << "Yes" << std::endl;
        }
    }
    return 0;
}