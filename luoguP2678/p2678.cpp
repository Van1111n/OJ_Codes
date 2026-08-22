#include <iostream>
#include <vector>
#include <algorithm>

int check(std::vector<int>& pos, int minGap) {
    auto p = pos.begin(), q = p;
    int count = 0;
    while (q < pos.end()-1) {
        p = q;
        q = p + 1;
        while (q < pos.end()-1 && *q - *p < minGap) {
            ++q;
        }
        count += q - p - 1;
    }
    if (*(pos.end()-1)-*p < minGap) {
        ++count;
    }
    return count;
}

int main() {
    int l, n, m;
    std::cin >> l >> n >> m;

    std::vector<int> positions(n+2);
    for (int i=1; i<=n; i++) {
        std::cin >> positions[i];
    }
    positions[n+1] = l;
    positions[0] = 0;

    int lo = 1, hi = l+1; 
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        int del = check(positions, mid);
        if (del > m) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    std::cout << lo;

    return 0;
}
