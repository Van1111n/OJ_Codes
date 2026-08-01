#include <iostream>
#include <vector>

using llong = long long;

struct Edge {
    int end;
    int weight;
};

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<Edge>> graph(N);
    int u, v, w;
    for (int i = 0; i < M; i++) {
        std::cin >> u >> v >> w;
        --u, --v;
        graph[u].push_back({v, w});
    }

    llong totalW = 0, nodeCountOnPath = 1;
    int crt = 0;
    while (!graph[crt].empty()) {
        int idx = nodeCountOnPath==1 ? 1 : 0;
        totalW = graph[crt][idx].weight;
        crt = graph[crt][idx].end;
        if (crt == N - 1) {
            if (nodeCountOnPath > N / 2) {
                std::cout << -1;
                return 0;
            } else {
                std::cout << totalW << std::endl;
                return 0;
            }
        }
        ++nodeCountOnPath;
    }
    std::cout << -1;
    return 0;
}