#include <iostream>
#include <cstring>

const int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

int main() {
    int n;
    std::cin >> n;

    char a[10], b[10];
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d", &b[i]);
    }

    if (n == 1 || n == 2 || strcmp(a, b) > 0) {
        std::cout << "0";
        return 0;
    }

    int ans = 0;
    int erase = 0;
    while (a[erase]==b[erase]) {++erase;}
    for (int i=0; i<n-erase; i++) {
        a[i] = a[i+erase];
        b[i] = b[i+erase];
    }
    n-=erase;

    for (int i=2; i<=n-1; i++) {
        int biggerElemCount = 0;
        for (int j=0; j<i-1; j++) {
            if (a[n-1-j] > a[n-i]) {
                ++biggerElemCount;
            }
        }
        ans += biggerElemCount * fact[i-1];
    }
    for (int i=2; i<=n-1; i++) {
        int smallerElemCount = 0;
        for (int j=0; j<i-1; j++) {
            if (b[n-1-j] < b[n-i]) {
                ++smallerElemCount;
            }
        }
        ans += smallerElemCount * fact[i-1];
    }
    int midElemCount = 0;
    for (int i=0; i<n; i++) {
        if (a[i] > a[0] && a[i] < b[0]) ++midElemCount;
    }
    ans += (midElemCount) * fact[n - 1];
    std::cout << ans;

    return 0;
}