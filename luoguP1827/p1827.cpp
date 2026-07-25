#include <iostream>
#include <vector>
#include <string>

std::string back(std::string mid, std::string front) {
    if(mid.length() == 0) return mid;
    char root = front[0];
    int rootInxInMid = mid.find(root);

    std::string lSubTreeMid = mid.substr(0, rootInxInMid), rSubTreeMid = mid.substr(rootInxInMid+1);
    std::string lSubTreeFront = front.substr(1, rootInxInMid), rSubTreeFront = front.substr(rootInxInMid+1);

    return back(lSubTreeMid, lSubTreeFront) + back(rSubTreeMid, rSubTreeFront) + root;
}

int main() {
    std::string mid, front;
    std::cin >> mid >> front;
    
    std::string ans = back(mid, front);
    std::cout << ans;
}