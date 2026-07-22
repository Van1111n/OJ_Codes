#include <iostream>
#include <map>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::map<int, int>> cabinet(100005);
    int mode, i, j, k;
    for (int u = 0; u < q; u++) {
        std::cin >> mode;
        if (mode == 1) {
            std::cin >> i >> j >> k;
            if (k == 0) {
                cabinet.at(i).erase(j);
            } else {
                cabinet.at(i).insert({j, k});
                // std::cout << "inserted!" << std::endl;
            }
        } else {
            std::cin >> i >> j;
            std::cout << cabinet.at(i).at(j) << std::endl;
        }
    }
    return 0;
}