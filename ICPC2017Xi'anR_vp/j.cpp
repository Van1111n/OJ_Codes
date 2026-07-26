#include <cstring>
#include <string>
#include <iostream>

const int mod = 1000000007;

int main() {

    char s1[100], s2[100], s3[100], s4[100], s5[100];
    char signal;
    while (1) {
        if (scanf("%s %s %s %s %s", s1, s2, s3, s4, s5)!=5) break;
        int heroCount5 = 0;
        for (int i = 0; i < 100; i++) {
            if (s5[i] == '1')
                ++heroCount5;
        }
        long long plan = 0;
        for (int i = 0; i < 100; i++) {
            if (s1[i] == '0')
                continue;
            for (int j = 0; j < 100; j++) {
                if (s2[j] == '0' || j == i)
                    continue;
                for (int k = 0; k < 100; k++) {
                    if (s3[k] == '0' || k == j || k == i)
                        continue;
                    for (int l = 0; l < 100; l++) {
                        if (s4[l] == '0' || l == k || l == j || l == i)
                            continue;
                        int available4p5 = heroCount5 - (s5[i] - '0') - (s5[j] - '0') - (s5[k] - '0') - (s5[l] - '0');
                        plan = (plan + available4p5) % mod;
                    }
                }
            }
        }
        plan = plan * 531192758 % mod;
        printf("%lld\n", plan);
    }

}