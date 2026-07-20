#include <iostream>
#include <cmath>

long long planCount = 0;

inline bool getbit(int a, int b) {
    if (b > 32) return false;
    return (a >> b) & 1;
}

void prt(int plate[], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", getbit(plate[i], j));
        }
        printf("\n");
    }
    printf("\n");
}

void dfs(int plate[], int curIdx, int maxN) {
    for (int i=0; i<maxN; i++) {
        plate[curIdx] = 1 << i;
        // prt(plate, maxN);

        bool valid = true;
        for (int j=0; j<curIdx; j++) {
            if(getbit(plate[j], i) 
            || (i+(curIdx-j) >= maxN ? 0 : getbit(plate[j], i+(curIdx-j))) 
            || (i-(curIdx-j) < 0 ? 0 : getbit(plate[j], i-(curIdx-j)))) {
                valid = false;
                break;
            }
        }
        if (!valid) continue;

        if (curIdx == maxN - 1) {
            ++planCount;
            if (planCount <= 3) {
                // print a solve;
                for (int i=0; i<maxN; i++) {
                    for (int j=0; j<maxN; j++) {
                        if (getbit(plate[i], j)) {
                            printf("%d ", j+1);
                        }
                    }
                }
                printf("\n");
            }
            continue;
        }
        dfs(plate, curIdx+1, maxN);
    }
    plate[curIdx] = 0;
}

int main() {
    int n;
    std::cin >> n;

    int plate[15] = {0};
    dfs(plate, 0, n);

    std::cout << planCount;

    return 0;
}