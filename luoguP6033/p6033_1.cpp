#include <iostream>
#include <queue>

using LLU = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    LLU buckets[100001] = {0};
    LLU temp;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        buckets[temp]++;
    }

    std::queue<LLU> q1, q2;
    for (int i = 1; i <= 100000; i++) {
        while (buckets[i] > 0) {
            --buckets[i];
            q1.push(i);
        }
    }

    LLU cost = 0;
    auto &fetch = q1, &store = q2;
    while (q1.size() + q2.size() >= 2) {
        LLU x;
        if (store.empty() || fetch.front() < store.front()) {
            x = fetch.front();
            fetch.pop();
        } else {
            x = store.front();
            store.pop();
        }
        if (fetch.empty()) {
            std::swap(fetch, store);
        }

        LLU y;
        if (store.empty() || fetch.front() < store.front()) {
            y = fetch.front();
            fetch.pop();
        } else {
            y = store.front();
            store.pop();
        }
        if (fetch.empty()) {
            std::swap(fetch, store);
        }

        store.push(x + y);
        cost += x + y;
    }
    std::cout << cost;
}