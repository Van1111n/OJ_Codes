#include <iostream>
#include <queue>
#include <vector>

int main() {
    int N, E, M, A;
    std::cin >> N >> E >> M >> A;
    --A;
    std::vector<int> a(N);
    for (auto& it : a) {
        std::cin >> it;
    }
    std::vector<std::vector<int>> graph(N);
    for (int i = 0; i < E; i++) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    std::vector<int> senders(M);
    for (auto& it : senders) {
        std::cin >> it;
        --it;
    }

    std::vector<char> sending(N, 0);
    std::queue<int> queue;
    for (auto it : senders) {
        queue.push(it);
        sending[it] = 1;
    }
    while (!queue.empty()) {
        int crt = queue.front();
        queue.pop();
        for (auto end : graph[crt]) {
            if (end == A)
                continue;
            if (a[end] > a[crt])
                continue;
            if (sending[end]) {
                if (a[end] < a[crt]) {
                    a[end] = a[crt];
                    queue.push(end);
                } else {
                    continue;
                }
            }
            sending[end] = 1;
            a[end] = a[crt];
            queue.push(end);
            continue;
        }
    }

    int cut = 0;
    for (auto guy : graph[A]) {
        if (sending[guy])
            ++cut;
    }
    std::cout << cut << std::endl;

    return 0;
}