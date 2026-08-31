#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> candidates(n);
    int unused = n;
    int unknownCount = 0;
    for (auto &it : candidates) {
        std::cin >> it;
        if (it != -1) {
            unused -= it;
        } else {
            ++unknownCount;
        }
    }

    auto max = candidates.begin();
    for (auto it = candidates.begin() + 1; it < candidates.end(); ++it) {
        if (*it > *max) {
            max = it;
        }
    }

    bool existOnlyMax = true;
    for (auto it = candidates.begin(); it < candidates.end(); ++it) {
        if (*it == *max && it != max) {
            existOnlyMax = false;
            break;
        } 
    }

    std::vector<int> possible;
    for (int i=0; i<n; i++) {
        if (candidates[i] == -1) {
            if (unused > *max) {
                possible.push_back(i+1);
            }
        }
    }
    if (existOnlyMax && (unknownCount == 0 || *max > (unused + unknownCount - 1) / unknownCount)) {
        possible.push_back(max-candidates.begin()+1);
    }
    std::sort(candidates.begin(), candidates.end());
    for (auto it : possible) {
        std::cout << it << ' ';
    }

    return 0;
}