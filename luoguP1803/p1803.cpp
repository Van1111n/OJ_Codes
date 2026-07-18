#include <iostream>
#include <queue>

class Contest {
   public:
    int startTime;
    int finishTime;

    Contest(int s, int f) {
        startTime = s;
        finishTime = f;
    }

    bool operator < (const Contest& other) {
        return finishTime < other.finishTime;
    }
    friend bool operator < (const Contest a, const Contest b) {
        return a.finishTime < b.finishTime;
    }
    friend bool operator > (const Contest a, const Contest b) {
        return a.finishTime > b.finishTime;
    }
};

int main() {
    int n;
    std::cin >> n;
    
    std::priority_queue<Contest, std::vector<Contest>, std::greater<Contest>> pq;
    int s, f;
    for (int i=0; i<n; i++) {
        std::cin >> s >> f;
        pq.push({s, f});
    }

    int participated = 0;
    int latestFreeTime = 0;
    while (!pq.empty()) {
        s = pq.top().startTime;
        f = pq.top().finishTime;
        pq.pop();
        if (s >= latestFreeTime) {
            ++participated;
            latestFreeTime = f;
        }
    }

    std::cout << participated << std::endl;
    return 0;
}