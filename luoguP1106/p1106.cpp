#include <iostream>
#include <string>

int main() {
    std::string s;
    int k;
    std::cin >> s >> k;

    // 使用'#'作为棍母字符
    int cur = 0;
    while (k > 0 && cur < s.length()) {
        for (int i = 1; i <= std::min(k, (int)(s.length() - cur - 1)); i++) {
            if (s[cur + i] < s[cur]) {
                k-=i;
                for (int j = cur; j < cur + i; j++) {
                    s[j] = '#';
                }
                cur = cur + i;
                goto found_to_del;
            }
        }
    nothing_to_del:
        ++cur;
        continue;
    found_to_del:
        continue;
    }
    if (k > 0) {
        for (int i=0; i<k; i++) {
            s[s.length()-1-i] = '#';
        }
    }

    int i = 0;
    while (i < s.length()-1 && (s[i] == '#' || s[i] == '0')) {
        ++i;
    }
    while (i<s.length()) {
        if (s[i] != '#') {
            std::cout << s[i];
        }
        ++i;
    }
}