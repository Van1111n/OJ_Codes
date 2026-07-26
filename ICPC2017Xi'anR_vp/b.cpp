#include <iostream>
#include <vector>
#include <algorithm>

const int MAXN = 200000;

int main() {
    int t, n, k;
    std::vector<int> a(MAXN+5), b(MAXN+5);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        for (int i=0; i<n; i++) {
            std::cin >> a[i];
        }
        for (int i=0; i<n; i++) {
            std::cin >> b[i];
        }
        std::sort(a.begin(), a.begin()+n);
        std::sort(b.begin(), b.begin()+n, std::greater<int>());

        int pairCount = 0;
        auto maxGirl = b.begin();
        for (auto boy = a.begin(); boy < a.begin()+n; ++boy) {
            if (*boy + *maxGirl >= k) {
                ++pairCount;
                ++maxGirl;
            } else {
                continue;
            }
        }
        std::cout << pairCount << std::endl;
    }

    return 0;
}