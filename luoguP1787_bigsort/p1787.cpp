#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Candidate {
    int id;
    string ticket;
};

bool large_num_compare(string a, string b) {
    if (a.length() > b.length()) {
        return true;
    }
    if (a.length() < b.length()) {
        return false;
    }
    for (int i=0; i<a.length(); i++){
        if (a.at(i) > b.at(i)) {
            return true;
        }
        if (a.at(i) < b.at(i)) {
            return false;
        }
    }
    return true;
}

bool candidate_compare(Candidate a, Candidate b){
    return large_num_compare(a.ticket, b.ticket);
}

int main(){
    int n;
    cin >> n;
    vector<Candidate> candidates(n);
    for (int i=0; i<n; i++){
        cin >> candidates.at(i).ticket;
        candidates.at(i).id=i+1;
    }
    sort(candidates.begin(), candidates.end(), candidate_compare);
    cout << candidates.at(0).id << endl << candidates.at(0).ticket;
    return 0;
}