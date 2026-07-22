#include <iostream>
#include <queue>
#include <utility>

class Meteor {
   public:
    int x;
    int y;
    int t;

    bool operator>(const Meteor& other) const {
        return t > other.t;
    }
};

struct Grid {
    int x;
    int y;
    int visitedTime;
};

int main() {
    int n;
    std::cin >> n;

    std::priority_queue<Meteor,std::vector<Meteor>, std::greater<Meteor>> pqMeteor;
    Meteor temp;
    for (int i = 0; i < n; i++) {
        std::cin >> temp.x >> temp.y >> temp.t;
        pqMeteor.push(temp);
    }

    int step[306][306];
    for (int i=0; i<=305; i++) {for (int j=0; j<=305; j++) {step[i][j]=1000;}}
    bool visited[306][306]{false};
    visited[0][0] = true;
    bool available[306][306];
    for (int i=0; i<=305; i++) {for (int j=0; j<=305; j++) {available[i][j]=true;}}
    std::queue<Grid> queue;
    queue.push({0, 0, 0});
    while (!pqMeteor.empty() && pqMeteor.top().t == 0) {
        int x = pqMeteor.top().x, y = pqMeteor.top().y;
            available[x][y] = false;
            if (x - 1 >= 0)
                available[x - 1][y] = false;
            if (y - 1 >= 0)
                available[x][y - 1] = false;
            if (x + 1 <= 305)
                available[x + 1][y] = false;
            if (y + 1 <= 305)
                available[x][y + 1] = false;
            pqMeteor.pop();
    }
    for (int t = 1;; t++) {
        while (!pqMeteor.empty() && pqMeteor.top().t == t) {
            int x = pqMeteor.top().x, y = pqMeteor.top().y;
            available[x][y] = false;
            if (x - 1 >= 0)
                available[x - 1][y] = false;
            if (y - 1 >= 0)
                available[x][y - 1] = false;
            if (x + 1 <= 305)
                available[x + 1][y] = false;
            if (y + 1 <= 305)
                available[x][y + 1] = false;
            pqMeteor.pop();
        }
        while (!queue.empty() && queue.front().visitedTime == t - 1) {
            int x = queue.front().x, y = queue.front().y;
            if (x - 1 >= 0 && available[x - 1][y] && !visited[x - 1][y])
                queue.push({x - 1, y, t}), visited[x - 1][y] = true, step[x - 1][y] = t;
            if (y - 1 >= 0 && available[x][y - 1] && !visited[x][y - 1])
                queue.push({x, y - 1, t}), visited[x][y - 1] = true, step[x][y - 1] = t;
            if (x + 1 <= 305 && available[x + 1][y] && !visited[x + 1][y])
                queue.push({x + 1, y, t}), visited[x + 1][y] = true, step[x + 1][y] = t;
            if (y + 1 <= 305 && available[x][y + 1] && !visited[x][y + 1])
                queue.push({x, y + 1, t}), visited[x][y + 1] = true, step[x][y + 1] = t;
            queue.pop();
        }
        
        if (pqMeteor.empty()) {
            int minStep = 1000;
            for (int i=0; i<=305; i++) {
                for (int j=0; j<=305; j++) {
                    if (available[i][j]) {
                        minStep = std::min(step[i][j], minStep);
                    }
                }
            }
            if (minStep == 1000) std::cout << -1;
            else std::cout << minStep << std::endl;
            return 0;
        }
        
        if (queue.empty()) {
            while (!pqMeteor.empty()) {
                int x = pqMeteor.top().x, y = pqMeteor.top().y;
                available[x][y] = false;
                if (x - 1 >= 0)
                    available[x - 1][y] = false;
                if (y - 1 >= 0)
                    available[x][y - 1] = false;
                if (x + 1 <= 305)
                    available[x + 1][y] = false;
                if (y + 1 <= 305)
                    available[x][y + 1] = false;
                pqMeteor.pop();
            }
            int minStep = 1000;
            for (int i=0; i<=305; i++) {
                for (int j=0; j<=305; j++) {
                    if (available[i][j]) {
                        minStep = std::min(step[i][j], minStep);
                    }
                }
            }
            if (minStep == 1000) std::cout << -1;
            else std::cout << minStep << std::endl;
            return 0;
        }
    }
    return 0;
}