#include <iostream>
#include <map>
#include <vector>

struct Graph {
    std::vector<std::vector<int>> adjList;
    std::vector<int> degree;
    int totalEdge;

    explicit Graph(int n) : adjList(n), degree(n, 0) { totalEdge = 0; }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
        degree[u]++, degree[v]++;
        totalEdge++;
    }

    bool validPair(int u, int v, int repeatEdge) {
        if (degree[u] + degree[v] - repeatEdge == totalEdge) {
            return true;
        } else {
            return false;
        }
    }

    int validPair(int a0, int b0) {
        std::map<int, int> repeatEdgeA, repeatEdgeB;
        for (auto e : adjList[a0]) {
            if (repeatEdgeA.find(e) == repeatEdgeA.end()) {
                repeatEdgeA.insert({e, 1});
            } else {
                repeatEdgeA[e]++;
            }
        }
        for (auto e : adjList[b0]) {
            if (repeatEdgeB.find(e) == repeatEdgeB.end()) {
                repeatEdgeB.insert({e, 1});
            } else {
                repeatEdgeB[e]++;
            }
        }

        int n = adjList.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i == a0 || i == b0) {
                continue;
            }
            if (validPair(a0, i, repeatEdgeA[i])) {
                ++ans;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i == a0 || i == b0) {
                continue;
            }
            if (validPair(b0, i, repeatEdgeB[i])) {
                ++ans;
            }
        }
        if (validPair(a0, b0, repeatEdgeA[b0])) {
            ++ans;
        }
        return ans;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph graph(n);
    int a0, b0;
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        if (i == 0) {
            a0 = u, b0 = v;
        }
        graph.addEdge(u, v);
    }

    int ans = graph.validPair(a0, b0);
    std::cout << ans;

    return 0;
}