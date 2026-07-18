#include <iostream>
#include <vector>

using LLU = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (auto& it : a) {
        std::cin >> it;
    }

    LLU eaten = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + a[i + 1] > x) {
            int sub = a[i] + a[i + 1] - x;
            if (sub > a[i + 1]) {
                a[i + 1] = 0;
                a[i] -= sub - a[i + 1];
            } else {
                a[i + 1] -= sub;
            }
            eaten += sub;
        }
    }

    std ::cout << eaten << std::endl;
    return 0;
}