#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>



class Point {
   public:
    double x;
    double y;
    bool visited;
};

std::vector<Point> points;
double** distanceMatrix = nullptr;

inline double distance(Point p, Point q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

double** preCalcDistance(std::vector<Point> points) {
    int n = points.size();
    double** matrix = new double*[n];
    for (int i=0; i<n; i++) matrix[i] = new double[n];

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix[i][j] = distance(points[i], points[j]);
        }
    }
    return matrix;
}

double greedy(std::vector<Point>& points) {
    Point start = {0, 0, true};
    double accumulatedDistance = 0;
    for (int i=0; i<points.size(); i++) {
        int closePointIdx;
        double closeDistance = INFINITY;
        for (int j = 0; j < points.size(); j++) {
            if (points[j].visited) continue;
            if (distance(points[j], start) < closeDistance) {
                closePointIdx = j;
                closeDistance = distance(points[j], start);
            }
        }
        accumulatedDistance += distance(start, points[closePointIdx]);
        start = points[closePointIdx];
        points[closePointIdx].visited = true;
    }
    for (auto &it : points) {it.visited = false;}
    return accumulatedDistance;
}

void dfs(Point start, std::vector<Point>& points, double accumulated, double& shortestFound) {
    if (accumulated > shortestFound)
        return;
    bool allVisited = true;
    for (auto& it : points) {
        if (it.visited)
            continue;
        allVisited = false;
        it.visited = true;
        dfs(it, points, accumulated + distance(start, it), shortestFound);
        it.visited = false;
    }
    if (allVisited) {
        if (accumulated < shortestFound)
            shortestFound = accumulated;
    }
}

void dfs(int start, std::vector<Point>& points, double accumulated, double& shortestFound) {
    if (accumulated > shortestFound)
        return;
    bool allVisited = true;
    for(int i=0; i<points.size(); i++) {
        if (points[i].visited) continue;
        allVisited = false;
        points[i].visited = true;
        dfs(i, points, accumulated + distanceMatrix[start][i], shortestFound);
        points[i].visited = false;
    }
    if (allVisited) { 
        if (accumulated < shortestFound) shortestFound = accumulated;
    } else return;
}



int main() {
    int n;
    std::cin >> n;
    points.resize(n+1);
    points[0] = {0, 0, false};
    for (int i = 1; i <= n; i++) {
        std::cin >> points[i].x >> points[i].y;
        points[i].visited = false;
    }
    distanceMatrix = preCalcDistance(points);

    double shortest = greedy(points);
    dfs(0, points, 0, shortest);
    std::cout << std::fixed << std::setprecision(2) << shortest;

    return 0;
}