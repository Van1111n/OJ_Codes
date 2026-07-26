#include <iostream>
#include <cstring>

int main() {
    int len, distance;
    char str[105];

    scanf("%d %d", &len, &distance);
    scanf("%s", str);

    int count = 0;
    for (int i=0; i<len; i++) {
        if (str[i]=='G') continue;
        int start = std::max(i - distance, 0);
        int end = std::min(i + distance, len - 1);
        bool guarded = false;
        for (int j=start; j<=end; j++) {
            if (str[j]=='G') {
                guarded = true;
                break;
            } else {
                continue;
            }
        }
        if (!guarded) {
            ++count;
        }
    }

    std::cout << count << std::endl;
    return 0;
}