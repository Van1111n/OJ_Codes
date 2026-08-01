#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string city, state;
    std::map<std::pair<std::string, std::string>, int> map;
    for (int i = 0; i < n; i++) {
        std::cin >> city >> state;
        city = city.substr(0, 2);
        if (city == state) continue;
        else {
            auto it = map.find({city, state});
            if (it != map.end()) {
                it->second++;
            } else {
                map.insert({{city, state}, 1});
            }
        }
    }

    int special = 0;
    for (auto p : map) {
        auto q = map.find({p.first.second, p.first.first});
        if (q != map.end()) {
            special += p.second * q->second;
        } else {
            continue;
        }
    }
    special /= 2;
    std::cout << special << std::endl;
    return 0;
}