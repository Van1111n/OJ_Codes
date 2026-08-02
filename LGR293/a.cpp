#include <iostream>
#include <stack>
#include <vector>

using llong = long long;
const llong mod = 993244853;

int popStack(std::vector<int>& queue) {
    int popCount = 0;
    std::stack<int> st;
    for (auto it : queue) {
        while (!st.empty() && st.top() >= it) {
            st.pop();
            ++popCount;
        }
        st.push(it);
    }
    return popCount;
}

int invPair(std::vector<int>& queue) {
    int n = queue.size();
    int inv = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (queue[i] > queue[j]) {
                ++inv;
            }
        }
    }
    return inv;
}

bool goodSequence(std::vector<int>& diff) {
    int n = diff.size();
    int biggestElemCantBePoped = -114514;
    int crt = 0;
    for (int i = 0; i < n; i++) {
        crt += diff[i];
        if (diff[i] < 0) {
            if (diff[i - 1] < 0) {
                return false;
            }
            if (i < n - 1 && diff[i + 1] + diff[i] < 0) {
                return false;
            }
            if (crt < biggestElemCantBePoped) {
                return false;
            }
            biggestElemCantBePoped = crt - diff[i];
        }
    }
    return true;
}

llong pow_mod(llong a, llong b) {
    llong ans = 1;
    while (b) {
        if (b % 2) {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

struct IO {
#define mxsz (1 << 21)
	char buf[mxsz], * p1, * p2;
	IO() : p1(buf), p2(buf) {}
	inline char gc() {
		if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, mxsz, stdin);
		return p1 == p2 ? ' ' : *p1++;
	}
	inline int read() {
		int r = 0; char c = gc(); bool rev = 0;
		while (c < '0' || c>'9') rev |= (c == '-'), c = gc();
		while (c >= '0' && c <= '9') r = r * 10 + (c ^ 48), c = gc();
		return rev ? ~r + 1 : r;
	}
} io;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    t = io.read();

    llong ans = 0;
    for (int i = 1; i <= t; i++) {
        int n;
        n = io.read();

        std::vector<int> diff(n);
        for (auto& it : diff) {
            it = io.read();
        }

        bool valid = goodSequence(diff);
        llong a = valid ? 65537 : 13579;
        ans += pow_mod(131, i) * a;
        ans %= mod;
    }
    std::cout << ans;
}