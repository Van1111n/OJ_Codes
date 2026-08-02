#include <algorithm>
#include <iostream>
#include <vector>

struct IO {
#define mxsz (1 << 21)
    char buf[mxsz], *p1, *p2;
    IO() : p1(buf), p2(buf) {}
    inline char gc() {
        if (p1 == p2)
            p2 = (p1 = buf) + fread(buf, 1, mxsz, stdin);
        return p1 == p2 ? ' ' : *p1++;
    }
    inline int read() {
        int r = 0;
        char c = gc();
        bool rev = 0;
        while (c < '0' || c > '9')
            rev |= (c == '-'), c = gc();
        while (c >= '0' && c <= '9')
            r = r * 10 + (c ^ 48), c = gc();
        return rev ? ~r + 1 : r;
    }
} io;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    int n, m;
    while (t--) {
        std::cin >> n >> m;
        std::vector<std::pair<int, int>> sets(n);
        for (auto& it : sets) {
            std::cin >> it.first >> it.second;
        }
        std::sort(sets.begin(), sets.end());

        int maxR = sets[0].second, minR = sets[0].second;
        // possible ans: 0, 2, 3.
        // ans = 0 : 任意两个集合均连通，即最大的l小于等于minR
        // ans = 2 : 存在一种划分，使两组集合的并不相交。因为最优的合并策略不可能合并不相交的两个集合，所以这等价于存在某个l>maxR
        // ans = 3 : 其他情况.
		int ans;
        bool ans2 = false;
        for (auto it : sets) {
            if (it.first > maxR) {
                ans2 = true;
				break;
            }
            maxR = std::max(maxR, it.second);
        }
		if (ans2) {
			std::cout << 2 << std::endl;
			continue;
		}

		for (auto it : sets) {
			minR = std::min(minR, it.second);
		}
        if (sets[n - 1].first <= minR) {
            std::cout << 0 << std::endl;
			continue;
        }

		std::cout << 3 << std::endl;
    }
}