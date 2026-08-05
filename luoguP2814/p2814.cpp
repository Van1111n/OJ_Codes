#include <iostream>
#include <map>
#include <string>

struct Unionfind {
    std::map<std::string, std::string> pa;

    std::string find(std::string son) {
        if (pa[son] == son) {
            return son;
        } else {
            return find(pa[son]);
        }
    }

    bool exist(std::string name) {
        if (pa.find(name) == pa.end()) {
            return false;
        } else {
            return true;
        }
    }

    void insert(std::string father, std::string son) {
        pa[son] = father;
    }
};

int main() {
    Unionfind unionfind;
    std::string temp;
    std::string crtFather, crtSon, ancester;
    while (1) {
        std::cin >> temp;
        switch (temp[0]) {
            case '#':
                crtFather = temp.substr(1);
                if (unionfind.exist(crtFather) == false) {
                    unionfind.insert(crtFather, crtFather);
                }
                break;
            case '+':
                crtSon = temp.substr(1);
                unionfind.insert(crtFather, crtSon);
                break;
            case '?':
                crtSon = temp.substr(1);
                ancester = unionfind.find(crtSon);
                std::cout << crtSon << ' ' << ancester << std::endl;
                break;
            case '$':
                goto end;
            default:
                break;
        }
    }
end:
    return 0;
}
