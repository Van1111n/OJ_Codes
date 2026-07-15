#include <iostream>
#include <string>
#include <cctype>
#include <stack>

struct Zipped{
    int repeat;
    std::string subStr;
};

std::string unzipStr(std::string& oldStr) {
    std::string newStr;
    std::stack<Zipped> st;
    
    auto c = oldStr.begin();
    while (c != oldStr.end()) {
        if (*c == '[') {
            ++c;
            int repeat = 0;
            while (isdigit(*c)) {
                repeat = 10 * repeat + (*c-'0');
                ++c;
            }
            st.push({repeat, ""});
            continue;
        } else if (*c == ']') {
            std::string unzip = "";
            for (int i = 0; i < st.top().repeat; i++) {
                unzip += st.top().subStr;
            }
            st.pop();
            if (st.empty()) {
                newStr += unzip;
            } else {
                st.top().subStr += unzip;
            }
        } 
        else {
            if (st.empty()) {
                newStr += *c;
            } else {
                st.top().subStr += *c;
            }
        }
        ++c;
    }
    return newStr;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << unzipStr(s) << std::endl;
}