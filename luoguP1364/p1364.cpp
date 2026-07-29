#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using llong = long long;

struct Node {
    int polulation;
    std::vector<int> edges;
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Node> graphAdjList(n);
    for (int i=0; i<n; i++) {
        std::cin >> graphAdjList[i].polulation;
        int lChild, rChild;
        std::cin >> lChild >> rChild;
        if (lChild) {
            graphAdjList[i].edges.push_back(lChild-1);
            graphAdjList[lChild-1].edges.push_back(i);
        }
        if (rChild) {
            graphAdjList[i].edges.push_back(rChild-1);
            graphAdjList[rChild-1].edges.push_back(i);
        }
    }
    llong minCost=LLONG_MAX;
    llong cost;
    for (int i=0; i<n; i++) {
        std::vector<int> dist(n); // distance from node[i] to other nodes
        std::vector<char> visited(n,0);
        dist[i] = 0;
        std::queue<int> queue;
        queue.push(i);
        while (!queue.empty()) {
            int crtNodeIdx = queue.front();
            queue.pop();
            visited[crtNodeIdx] = 1;
            for (auto end : graphAdjList[crtNodeIdx].edges) {
                if (visited[end]) continue;
                dist[end] = dist[crtNodeIdx]+1;
                queue.push(end);
            }
        }
        cost = 0;
        for (int i=0; i<n; i++) {
            cost += graphAdjList[i].polulation * dist[i];
        }
        minCost = std::min(minCost, cost);
    }
    std::cout << minCost << std::endl;
    return 0;
}