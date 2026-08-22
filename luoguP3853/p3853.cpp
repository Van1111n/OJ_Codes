#include <iostream>
#include <vector>

int check(std::vector<int>& gaps, int minGap) {
    int add = 0;
    for (auto it : gaps) {
        add += (it - 1) / minGap;
    }
    return add;
}

int main() {
    int l, n, k;
    std::cin >> l >> n >> k;
    
    std::vector<int> pos(n);
    for (auto& it : pos) {
        std::cin >> it;
    }
    std::vector<int> gaps(n-1);
    for (int i=0; i<n-1; i++) {
        gaps[i] = pos[i+1]-pos[i];
    }

    int lo = 0, hi = l;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        int add = check(gaps, mid);
        if (add > k) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    std::cout << hi << std::endl;

    return 0;
}