#include <cctype>
#include <cstring>
#include <iostream>
#include <stack>

inline int calc(int a, int b, char opr) {
    if (opr == '+') {
        return a + b;
    } else if (opr == '-') {
        return a - b;
    } else if (opr == '*') {
        return a*b;
    } else if (opr == '/') {
        return a/b;
    } else {
        throw "invalid opr\n";
    }
}

int main() {
    std::stack<int> numStack;
    char expression[64];
    char numBuf[16];

    scanf("%s", expression);
    char* q = numBuf;
    for (char* p = expression; *p != '\0'; ++p) {
        if (isdigit(*p)) {
            *q = *p;
            ++q;
        } else if (*p == '.') {
            *q = '\0';
            numStack.push(atoi(numBuf));
            q = numBuf;
        } else if (*p == '@') {
            printf("%d\n", numStack.top());
            numStack.pop();
        } else {
            char opr = *p;
            int a = numStack.top();
            numStack.pop();
            int b = numStack.top();
            numStack.pop();
            int result = calc(b,a,opr);
            numStack.push(result);
        }
    }
}