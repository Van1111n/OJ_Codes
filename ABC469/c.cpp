#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int p = 0, q = 0;
    while (p < n) {
        while (q < n && s[q] == 'o') {
            ++q;
        }
        std::cout << std::min(q + 1, n) << '\n';
        ++p;
        if (q < n) {
            ++q;
        }
        continue;
    }

    return 0;
}