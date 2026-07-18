#include <iostream>
#include <algorithm>
#include <vector>

class WaterMan {
   public:
    int number;
    double time;

    bool operator < (const WaterMan& other) {
        if (time != other.time)
            return time < other.time;
        else
            return number < other.number;
    }
};

main() {
    int n;
    std::cin >> n;
    std::vector<WaterMan> queue;
    queue.resize(n);

    for (int i=0; i<n; i++) {
        std::cin >> queue[i].time;
        queue[i].number = i+1;
    }

    std::sort(queue.begin(), queue.end());

    double sum = 0;
    for (int i=0; i<n; i++) {
        sum += (n-i-1) * queue[i].time;
    }
    double avg = sum / n;
    
    for (auto it : queue) {
        std::cout << it.number << ' ';
    }
    putchar('\n');
    printf("%.2lf", avg);
    return 0;
}