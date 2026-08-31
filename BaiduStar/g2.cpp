#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> candidates(n);
    int unknownCount = 0;
    int unused = n;
    for (auto &it :candidates) {
        std::cin >> it;
        if (it == -1) {
            unknownCount++;
        } else {
            unused -= it;
        }
    }

    int max = 0;
    for (int i=0; i<n; i++) {
        if (candidates[i] > candidates[max]) {
            max = i;
        }
    }

    bool existOnlyMax = true;
    for (int i=0; i<n; i++) {
        if (candidates[i]==candidates[max] && i!=max) {
            existOnlyMax = false;
            break;
        }
    }

    std::vector<int> possible;
    if (unused > candidates[max]) {
        for (int i=0; i<n; i++) {
            if (candidates[i] == -1) {
                possible.push_back(i+1);
            }
        }
    }
    int minMaxPossibleTickets4Unknown;
    if (unknownCount == 0) {
        minMaxPossibleTickets4Unknown = 0;
    } else {
        minMaxPossibleTickets4Unknown = unused / unknownCount + (unused % unknownCount == 0 ? 0 : 1);
    }
    if (existOnlyMax && candidates[max] > minMaxPossibleTickets4Unknown) {
        possible.push_back(max+1);
    }

    std::sort(possible.begin(), possible.end());
    for (auto it : possible) {
        std::cout << it << ' ';
    }

    return 0;


}