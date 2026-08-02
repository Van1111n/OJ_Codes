#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using ullong = unsigned long long;

class StrHash {
   private:
    std::vector<std::vector<std::string>> hashTable;
    ullong base, tableSize;
    ullong size;

   public:
    explicit StrHash(ullong base, ullong tableSize) : hashTable(tableSize), base(base), tableSize(tableSize) {
        size = 0;
    }

    // core code
    const ullong hashFunc(const std::string& s) {
        ullong key = 0;
        for (auto c : s) {
            key = key * base + c;
        }
        return key;
    }

    void insert(const std::string& s) {
        ullong idx = hashFunc(s) % tableSize;
        bool exist = false;
        for (auto it : hashTable[idx]) {
            if (it == s) {
                exist = true;
                break;
            }
        }
        if (!exist) {
            hashTable[idx].push_back(s);
            ++size;
        }
        return;
    }

    inline ullong getSize() {
        return size;
    }
};

int main() {
    int n;
    std::cin >> n;

    std::string s;
    StrHash ht(107, 110503);
    for (int i=0; i<n; i++) {
        std::cin >> s;
        ht.insert(s);
    }
    std::cout << ht.getSize();
}