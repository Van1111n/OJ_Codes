#include <iostream>
#include <vector>
#include <algorithm>

int minTIme(std::vector<int>& seq) {
    int sum = 0;
    for (auto it : seq) {
        sum += it;
    }

    std::vector<int> dp(sum / 2 + 1, 0);
    for (int t : seq) {
        for (int j = sum/2; j>=0; j--) {
            if (j-t < 0) continue;
            dp[j] = std::max(dp[j], dp[j-t]+t);
        }
    }
    return std::max(dp[sum/2], sum-dp[sum/2]);
}

int main() {
    int aLen, bLen, cLen, dLen;
    std::cin >> aLen >> bLen >> cLen >> dLen;
    std::vector<int> vecA(aLen), vecB(bLen), vecC(cLen), vecD(dLen);
    for (auto& it : vecA) {
        std::cin >> it;
    }
    for (auto& it : vecB) {
        std::cin >> it;
    }
    for (auto& it : vecC) {
        std::cin >> it;
    }
    for (auto& it : vecD) {
        std::cin >> it;
    }
    int time = 0;
    time += minTIme(vecA);
    time += minTIme(vecB);
    time += minTIme(vecC);
    time += minTIme(vecD);
    std::cout << time;
    return 0;
}