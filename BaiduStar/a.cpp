#include <algorithm>
#include <iostream>
#include <queue>

#define int long long

struct Monster {
    int atk;
    int profit;
};

bool operator>(const Monster& a, const Monster& b) {
    return a.atk > b.atk;
}

signed main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, portion, initAtk;
        std::cin >> n >> portion >> initAtk;
        std::priority_queue<Monster, std::vector<Monster>, std::greater<Monster>> monsters;
        int atkTemp, profitTemp;
        for (int i = 0; i < n; i++) {
            std::cin >> atkTemp >> profitTemp;
            monsters.push({atkTemp, profitTemp});
        }
        // 打所有能打的怪
        // 如果没有能打的了，喝一瓶药水
        // 结束条件：没有怪物剩下，或者药水喝完且没有能打的怪
        int myAtk = initAtk;
        while (1) {
            while (!monsters.empty() && monsters.top().atk <= myAtk) {
                myAtk += monsters.top().profit;
                monsters.pop();
            }
            if (portion >= 1) {
                --portion;
                myAtk *= 2;
            } else {
                break;
            }
        }
        if (portion >= 1) {
            myAtk <<= portion;
        }
        std::cout << myAtk << std::endl;
    }
}