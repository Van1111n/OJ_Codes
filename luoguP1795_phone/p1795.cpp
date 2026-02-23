#include <iostream>

using namespace std;

int main(){
    char c;
    int count=0;
    while ((c=getchar())!='\n'){
        if (c == ' ') {
            count += 1;
        }
        if ('a' <= c && c <= 'o') {
            count += (c - 'a') % 3 + 1;
        }
        if ('p' <= c && c <= 's') {
            count += c - 'o';
        }
        if ('t' <= c && c <= 'v') {
            count += c - 's';
        }
        if ('w' <= c && c <= 'z') {
            count += c - 'v';
        }
    }
    printf("%d", count);
}