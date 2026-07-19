#include <cmath>
#include <iostream>

using LLD = signed long long;

struct Point {
    LLD x;
    LLD y;
};

int main() {
    int t;
    Point p, q, r, s;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> p.x >> p.y >> q.x >> q.y >> r.x >> r.y >> s.x >> s.y;
        // 两条直线没有交点，当且仅当它们平行且不重合。
        if ((p.x - q.x) * (r.y - s.y) == (r.x - s.x) * (p.y - q.y)) { //线段PQ和RS平行的判据
            if (p.x * p.x - q.x * q.x - p.x * r.x - p.x * s.x + q.x * r.x + q.x * s.x +
                p.y * p.y - q.y * q.y - p.y * r.y - p.y * s.y + q.y * r.y + q.y * s.y == 0) { // PQ与RS中点的连线垂直于PQ的判据，在平行基础上可推出两条中垂线重合
                std::cout << "Yes" << std::endl;
            } else {
                std::cout << "No" << std::endl;
            }
        } else {
            std::cout << "Yes" << std::endl;
        }
    }
    return 0;
}