#include <algorithm>
#include <iostream>
#include <vector>

struct Castle {
    int p, s;

    int cost() {
        return p + s;
    }

    bool operator<(const Castle& other) {
        return p + s < other.p + other.s;
    }
};

int main() {
    int n, b;
    std::cin >> n >> b;

    std::vector<Castle> castles(n);
    for (auto& it : castles) {
        std::cin >> it.p >> it.s;
    }

    std::sort(castles.begin(), castles.end());
    auto it_1 = castles.begin();
    while (it_1 < castles.end()) {
        int cost = it_1->p + it_1->s;
        if (cost <= b) {
            b -= cost;
            ++it_1;
        } else {
            break;
        }
    }
    int supported = it_1 - castles.begin();

    for (auto it_2 = castles.begin(); it_2 < it_1; ++it_2) {
        if (it_2->p / 2 + b >= it_1->p + it_1->s) {
            ++supported;
            goto output;
        }
    }
    for (auto it_2 = it_1; it_2 < castles.end(); ++it_2) {
        if (b >= it_2->p / 2 + it_2->s) {
            ++supported;
            goto output;
        }
    }

output:
    std::cout << supported << std::endl;

    return 0;
}