#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> win(n + 1);
    for (int i = 0; i < n + 1; i++) {
        win[i].first = i;
        win[i].second = 0;
    }
    std::vector<std::pair<int, int>> matches(m);
    for (int i = 0; i < m; i++) {
        std::cin >> matches[i].first >> matches[i].second;
        win[matches[i].first].second++;
        win[matches[i].second].second++;
    }
    std::sort(win.begin(), win.end(), [](std::pair<int, int> a, std::pair<int, int> b) { return a.second > b.second; });
    win.pop_back();

    int ans = 0;
    for (auto p = win.begin(); 2 * p->second >= m; p++) {
        for (auto q = p + 1; p->second + q->second >= m; q++) {
            bool covered = true;
            for (auto r : matches) {
                if (r.first != p->first && r.second != p->first && r.first != q->first && r.second != q->first) {
                    covered = false;
                    break;
                }
            }
            if (covered) {
                ++ans;
            }
        }
    }
    std::cout << ans;

    return 0;
}