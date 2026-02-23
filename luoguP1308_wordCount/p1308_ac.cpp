#include <iostream>
#include <limits.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
    string article, targetWord;
    int count = 0, pos = INT_MAX;
    cin >> targetWord;
    getchar();
    getline(cin, article);
    transform(targetWord.begin(), targetWord.end(), targetWord.begin(), ::tolower);
    transform(article.begin(), article.end(), article.begin(), ::tolower);
    article = " " + article + " ";
    for (size_t i = 1; i <= article.length()-1 - targetWord.length(); i++) {
        bool found = true;
        for (size_t j = 0; j < targetWord.length(); j++) {
            if (article.at(i + j) != targetWord.at(j)) {
                found = false;
                break;
            }
        }
        if (article.at(i - 1) != ' ' || article.at(i + targetWord.length()) != ' ') {
            found = false;
        }
        if (found) {
            count++;
            pos = pos < i ? pos : i;
        }
    }
    if (count)
        printf("%d %d", count, pos-1);
    else
        printf("-1");
    return 0;
}