#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

int segNum(std::vector<int> &logs, int segLenth) {
    int res = 0;
    for (auto it : logs) {
        res += it / segLenth;
    }
    return res;
}

int main() {
    int n, requireSegNum;
    std::cin >> n >> requireSegNum;

    std::vector<int> woods;
    int woodMaxLen = 0, woodMinLen = INT_MAX;
    woods.resize(n);
    for (int i=0; i<n; i++) {
        std::cin>>woods[i];
        woodMaxLen = std::max(woodMaxLen, woods[i]);
        woodMinLen = std::min(woodMinLen, woods[i]);
    }

    // find max lenth, s.t. segNum(woods, length) >= requireSegNum
    // smaller length, bigger segNum.
    int lenL = woodMaxLen;
    while(segNum(woods, lenL) < requireSegNum){
        lenL /= 2;
        if (lenL == 0) {
            std::cout << 0;
            return 0;
        }
    }
    int lenR = lenL * 2;

    while (lenR - lenL > 1) {
        int lenMid = (lenR + lenL) / 2;
        if (segNum(woods, lenMid) >= requireSegNum) {
            lenL = lenMid;
        } else {
            lenR = lenMid;
        }
    }
    std::cout << lenL;

    return 0;
}