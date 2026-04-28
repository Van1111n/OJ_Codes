#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> names;
    int realationships[500];
    string s;
    cin >> s;
    int nameIdx = 0;
    int relIdx = 0;
    int i = 0;
    while (i < s.length()) {
        if (isalpha(s.at(i))) {
            int j = i;
            while (j < s.length()&& isalpha(s.at(j)))
                ++j;
            string name = s.substr(i, j - i);
            names.insert({name, nameIdx++});
            i = j;
        } else {
            if (s[i] == '<' && s[i + 1] == '=' && s[i + 2] == '>') {
                realationships[relIdx++] = 0;
                i = i + 3;
            } else if (s[i] == '<' && s[i + 1] == '=') {
                realationships[relIdx++] = -1;
                i = i + 2;
            } else if (s[i] == '=' && s[i + 1] == '>') {
                realationships[relIdx++] = 1;
                i = i + 2;
            } else {
                printf("wtf");
            }
        }
    }
    return 0;
}
