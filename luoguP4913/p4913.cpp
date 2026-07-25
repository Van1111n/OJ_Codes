#include <iostream>
#include <utility>
#include <vector>

int depth(std::vector<std::pair<int, int>>& v, int k) {
    if (v[k].first == 0 && v[k].second == 0) {
        return 1;
    } else {
        return 1 + std::max(depth(v, v[k].first), depth(v, v[k].second));
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> v(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i].first >> v[i].second;
    }

    std::cout << depth(v, 1);
}