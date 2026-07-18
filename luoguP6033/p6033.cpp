#include <cstdio>
#include <queue>

int main() {
    int n;
    scanf("%d", &n);

    std::priority_queue<unsigned long long, std::vector<unsigned long long>, std::greater<unsigned long long>> pq;
    int a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        pq.push(a);
    }

    unsigned long long total = 0;
    unsigned long long x, y;
    while (pq.size() >= 2) {
        x = pq.top();
        pq.pop();
        y = pq.top();
        pq.pop();
        total += x + y;
        pq.push(x + y);
    }
    printf("%llu", total);

    return 0;
}