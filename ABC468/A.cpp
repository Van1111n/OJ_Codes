#include <iostream>

int main() {
    int n;
    int a[105];
    std::cin >> n;
    for (int i=1; i<=n; i++) {
        std::cin >> a[i];
    }

    int count = 0;
    for (int i=1; i<=n-2; i++) {
        if (a[i] < a[i+1] && a[i+1] > a[i+2]) {
            ++count;
        }
    }
    std::cout << count;

    return 0;
}