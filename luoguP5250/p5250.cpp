#include <iostream>
#include <set>

int main() {
    int m;
    std::cin >> m;

    int type, length;
    std::set<int> logs;
    for (int i = 0; i < m; i++) {
        std::cin >> type >> length;
        switch (type) {
            case 1: {
                if (logs.insert(length).second == false) {
                    std::cout << "Already Exist" << std::endl;
                };
                break;
            }
            case 2: {
                if (logs.empty()) {
                    std::cout << "Empty" << std::endl;
                    break;
                }
                auto it = logs.find(length);
                if (it != logs.end()) {
                    std::cout << *it << std::endl;
                    logs.erase(it);
                } else {
                    auto bigger = logs.lower_bound(length);
                    if (bigger == logs.end()) {
                        std::cout << *(--bigger) << std::endl;
                        logs.erase(bigger);
                        break;
                    }
                    if (bigger == logs.begin()) {
                        std::cout << *bigger << std::endl;
                        logs.erase(bigger);
                        break;
                    }
                    auto smaller = bigger;
                    --smaller;
                    if (*bigger - length >= length - *smaller) {
                        std::cout << *smaller << std::endl;
                        logs.erase(smaller);
                    } else {
                        std::cout << *bigger << std::endl;
                        logs.erase(bigger);
                    }
                }
                break;
            }
            default:
                break;
        }
    }
    return 0;
}