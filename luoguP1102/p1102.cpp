#include <iostream>
#include <map>
#define int long long

class NumStat : public std::map<int, int> {
   public:
    void add(int a) {
        this->operator[](a)++;
    }
};

signed main() {
    int n, c;
    NumStat numStat;
    std::cin >> n >> c;
    int a;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        numStat.add(a);
    }

    int ans = 0;
    for (auto p : numStat) {
        int b = p.first - c;
        auto q = numStat.find(b);
        if (q != numStat.end()) {
            ans += p.second * q->second;
        }
    }
    std::cout << ans << '\n';

    return 0;
}