#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Statistic{
    public:
    char letter;
    int count;
};

int find(char target, vector<Statistic> statistics){
    int k;
    for (k = 0; k < statistics.size(); k++){
        if (statistics.at(k).letter==target){
            return k;
        }
    }
    return -1;
}

int is_Prime_Under_100(int n){
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    for (int i=0; i<25; i++){
        if (n==primes[i]) return 1;
    }
    return 0;
}

int main(){
    vector<Statistic> statistics;
    string word;
    cin >> word;
    int pos;
    for (int i=0; i<word.length(); i++){
        if ((pos = find(word.at(i), statistics)) != -1){
            statistics.at(pos).count++;
        }
        else statistics.push_back({word.at(i), 1});
    }
    int max, min;
    max=min=statistics.at(0).count;
    for (int i=0; i<statistics.size(); i++){
        if (statistics.at(i).count > max) max=statistics.at(i).count;
        if (statistics.at(i).count < min) min=statistics.at(i).count;
    }
    if (is_Prime_Under_100(max-min)) cout << "Lucky Word" << endl << max-min;
    else cout << "No Answer" << endl << 0;
}