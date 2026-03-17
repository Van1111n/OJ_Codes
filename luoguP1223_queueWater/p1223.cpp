#include <algorithm>
#include <iostream>
#include <vector>

struct Man {
    int num;
    int time;

    bool operator<(const Man& it) {
        if (time<it.time) return true;
        if (time == it.time && num < it.num) return true;
        return false;
    }
};

int main() {
    int n;
    float sum = 0, avg = 0, ssum = 0;
    scanf("%d", &n);
    std::vector<Man> vec;
    for (int i = 0; i < n; i++) {
        Man temp;
        scanf("%d", &temp.time);
        temp.num = i + 1;
        vec.push_back(temp);
    }
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++) {
        printf("%d ", vec.at(i).num);
        ssum += sum;
        sum += (float)vec.at(i).time;
    }
    printf("\n");
    avg = ssum / n;
    printf("%.2f\n", avg);
    return 0;
}