#include <iostream>
#include <map>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int q;
    std::cin >> q;

    std::string name;
    int op, score;
    std::map<std::string, int> map;
    while (q--) {
        std::cin >> op;
        switch (op) {
            case 1: {
                std::cin >> name >> score;
                map[name] = score;
                std::cout << "OK\n";
                break;
            }
            case 2: {
                std::cin >> name;
                auto it = map.find(name);
                if (it == map.end()) {
                    std::cout << "Not found\n";
                } else {
                    std::cout << it->second << '\n';
                }
                break;
            }
            case 3: {
                std::cin >> name;
                auto it = map.find(name);
                if (it == map.end()) {
                    std::cout << "Not found\n";
                } else {
                    map.erase(it);
                    std::cout << "Deleted successfully\n";
                }
                break;
            }
            case 4: {
                std::cout << map.size() << '\n';
                break;
            }
            default:
                break;
        }
    }
}