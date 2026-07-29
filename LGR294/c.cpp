#include <iostream>
#include <climits>

int main() {
    int n, m;
    std::cin >> n >> m;
    int max[1005]={0};
    int min = INT_MAX;
    int temp;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            std::cin >> temp;
            max[i] = std::max(max[i], temp);
        }
        min = std::min(max[i], min);
    }
    std::cout << min;
    return 0;
}