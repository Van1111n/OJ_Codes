#include <array>
#include <iostream>
#include <vector>
using namespace std;

int sum(array<int, 10> a) {
    int res = 0;
    for (int i = 0; i < 10; i++) {
        res += a[i];
    }
    return res;
}

void prt(array<int, 10> a) {
    for (int i = 0; i < 10; i++) {
        printf("%d", a[i]);
        if (i == 9)
            printf("\n");
        else
            printf(" ");
    }
}

int main() {
    int n;
    array<int, 10> a;
    vector<array<int, 10>> ans;
    scanf("%d", &n);
    if (n < 10 || n > 30) {
        printf("0");
        return 0;
    }

    for (a[0] = 1; a[0] <= 3; a[0]++) {
        for (a[1] = 1; a[1] <= 3; a[1]++) {
            for (a[2] = 1; a[2] <= 3; a[2]++) {
                for (a[3] = 1; a[3] <= 3; a[3]++) {
                    for (a[4] = 1; a[4] <= 3; a[4]++) {
                        for (a[5] = 1; a[5] <= 3; a[5]++) {
                            for (a[6] = 1; a[6] <= 3; a[6]++) {
                                for (a[7] = 1; a[7] <= 3; a[7]++) {
                                    for (a[8] = 1; a[8] <= 3; a[8]++) {
                                        for (a[9] = 1; a[9] <= 3; a[9]++) {
                                            if (sum(a) == n) {
                                                ans.push_back(a);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%llu\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        prt(ans.at(i));
    }
    
}
