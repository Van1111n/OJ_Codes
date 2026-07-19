#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
    bool visited;
};

double distance(Point p, Point q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

double s_path(Point start, std::vector<Point>& points) {
    double shortest = INFINITY;
    for (auto& it : points) {
        if (it.visited)
            continue;
        it.visited = true;
        shortest = std::min(shortest, distance(start, it) + s_path(it, points));
        it.visited = false;
    }
    if (std::isinf(shortest))
        return 0.0;
    else
        return shortest;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
        points[i].visited = false;
    }

    double ans = s_path({0, 0, true}, points);
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
}