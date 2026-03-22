#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Charactor {
    string name;
    vector<string> operates;
    vector<string> resType;
    vector<string> resName;
    vector<string> authObjList;

    bool check(string tOperate, string tResType, string tResName) {
        if (find(operates.begin(), operates.end(), tOperate) == operates.end() && find(operates.begin(), operates.end(), "*") == operates.end()) {
            return false;
        }
        if (find(resType.begin(), resType.end(), tResType) == resType.end() && find(resType.begin(), resType.end(), "*") == resType.end()) {
            return false;
        }
        if (find(resName.begin(), resName.end(), tResName) == resName.end() && resName.size() != 0) {
            return false;
        }
        return true;
    }
};

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    vector<Charactor> charactors;
    for (int i = 0; i < n; i++) {
        Charactor temp;
        cin >> temp.name;
        int nv;
        scanf("%d", &nv);
        for (int j = 0; j < nv; j++) {
            string s;
            cin >> s;
            temp.operates.push_back(s);
        }
        int no;
        scanf("%d", &no);
        for (int j = 0; j < no; j++) {
            string s;
            cin >> s;
            temp.resType.push_back(s);
        }
        int nn;
        scanf("%d", &nn);
        for (int j = 0; j < nn; j++) {
            string s;
            cin >> s;
            temp.resName.push_back(s);
        }
        charactors.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        string relateCharacName;
        cin >> relateCharacName;
        auto it = charactors.begin();
        while (it->name != relateCharacName)
            ++it;
        int ns;
        string objType, objName;
        scanf("%d", &ns);
        for (int j = 0; j < ns; j++) {
            cin >> objType;
            cin >> objName;
            it->authObjList.push_back(objName);
        }
    }
    for (int i = 0; i < q; i++) {
        vector<string> obj;
        vector<Charactor> allowed;
        string s;
        cin >> s;
        obj.push_back(s);
        int ng;
        scanf("%d", &ng);
        for (int j = 0; j < ng; j++) {
            cin >> s;
            obj.push_back(s);
        }
        for (auto p = obj.begin(); p < obj.end(); ++p) {
            for (auto q = charactors.begin(); q < charactors.end(); ++q) {
                if (find(q->authObjList.begin(), q->authObjList.end(), *p) != q->authObjList.end()) {
                    allowed.push_back(*q);
                }
            }
        }
        string oprerate, resType, resName;
        bool found = false;
        cin >> oprerate >> resType >> resName;
        for (auto p = allowed.begin(); p < allowed.end(); ++p) {
            if (p->check(oprerate, resType, resName)) {
                printf("1\n");
				found = true;
                break;
            }
        }
		if (found==false) printf("0\n");
    }
    return 0;
}