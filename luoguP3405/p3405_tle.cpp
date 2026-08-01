#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string city, state;
    std::multimap<std::string, std::string> table;
    for (int i = 0; i < n; i++) {
        std::cin >> city >> state;
        table.insert({state, city});
    }

    int special = 0;
    for (auto it : table) {
        auto prev2 = it.second.substr(0, 2);
        if (prev2 == it.first)
            continue;
        auto range = table.equal_range(prev2);
        for (auto it2 = range.first; it2 != range.second; ++it2) {
            if (it2->second.substr(0, 2) == it.first) {
                ++special;
            }
        }
    }
    special /= 2;
    std::cout << special << std::endl;
}