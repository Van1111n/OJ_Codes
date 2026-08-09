#include <iostream>
#include <vector>
#include <stack>
#include <numeric>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> revAdjList(n+1);
    std::vector<bool> visited(n+1, false);
    std::vector<int> largestReachable(n+1);
    std::iota(largestReachable.begin(), largestReachable.end(), 0);
    int u, v;
    while (m--) {
        std::cin >> u >> v;
        revAdjList[v].push_back(u);
    }
    for (int start = n; start >= 1; start--) {
        if (visited[start]) continue;

        std::stack<int> st;
        st.push(start);
        visited[start] = true;
        while (!st.empty()) {
            auto crt = st.top();
            st.pop();
            for (auto e : revAdjList[crt]) {
                if (visited[e]) continue;
                visited[e] = true;
                largestReachable[e] = start;
                st.push(e);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        std::cout << largestReachable[i] << ' ';
    }
    std::cout << std::endl;
    return 0;
}