#include <iostream>
#include <queue>
#include <vector>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    --a;
    --b;

    int floors[205], steps[205];
    bool visited[205] = {false};
    for (int i = 0; i < 205; i++) {
        steps[i] = 1e5;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> floors[i];
    }

    std::queue<int> queue;
    steps[a] = 0;
    queue.push(a);
    visited[a] = true;
    while (!queue.empty() && !visited[b]) {
        int crt = queue.front();
        queue.pop();
        int up = crt + floors[crt], down = crt - floors[crt];
        if (0 <= up && up < n && !visited[up]) {
            steps[up] = steps[crt] + 1;
            queue.push(up);
            visited[up] = true;
        }
        if (0 <= down && down < n && !visited[down]) {
            steps[down] = steps[crt] + 1;
            queue.push(down);
            visited[down] = true;
        }
    }
    if (visited[b])
        std::cout << steps[b];
    else
        std::cout << -1;
}