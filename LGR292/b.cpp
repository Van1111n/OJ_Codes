#include <iostream>
#include <numeric>
#include <vector>

#define int long long

signed main() {
    int n;
    std::cin >> n;

    std::vector<int> dist(n - 1);
    std::vector<int> movable(n);
    for (auto& it : dist) {
        std::cin >> it;
    }
    for (auto& it : movable) {
        std::cin >> it;
    }

    int start = 0, finish = 0;
    int wrongPos = 0;
    while (start < n-1) {
        finish = start + 1;
        int segLen = dist[start];
        while (movable[finish]) {
            segLen += dist[finish];
            ++finish;
        }

        int accumulatedDistance = dist[start];
        int periodCount = finish - start;
        for (int i = start + 1; i < finish; i++) {
            if (accumulatedDistance * periodCount != (i - start) * segLen) {
                ++wrongPos;
            }
            accumulatedDistance += dist[i];
        }
        start = finish;
    }
    std::cout << wrongPos << std::endl;
}