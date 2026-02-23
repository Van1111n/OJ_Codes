#include <algorithm>
#include <ctype.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    char type;
    vector<string> v;
    string s, res;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        v.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        int j = 0;
        int num1 = 0, num2 = 0;
        if (isalpha(v.at(i).at(0))) {
            type = v.at(i).at(0);
            j += 2;
        }
        while (v.at(i).at(j) != ' ') {
            num1 *= 10;
            num1 += v.at(i).at(j) - '0';
            j++;
        }
        j++;
        while (j < v.at(i).length()) {
            num2 *= 10;
            num2 += v.at(i).at(j) - '0';
            j++;
        }
    
        string op;
        int ans;
        switch (type) {
        case 'a':
            op = "+";
            ans = num1 + num2;
            break;
        case 'b':
            op = "-";
            ans = num1 - num2;
            break;
        case 'c':
            op = "*";
            ans = num1 * num2;
            break;
        }
        res = to_string(num1) + op + to_string(num2) + "=" + to_string(ans);
        cout << res << endl << res.length() << endl;
    }

    return 0;
}