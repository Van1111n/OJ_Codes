#include <iostream>
#include <string>

using namespace std;

int main() {
    int q, a, b, type;
    string doucment, str;
    scanf("%d", &q);
    cin >> doucment;

    for (int i = 0; i < q; i++) {
        scanf("%d ", &type);
        switch (type) {
        case 1:
            cin >> str;
            doucment = doucment + str;
            cout << doucment << endl;
            break;
        case 2:
            scanf("%d %d", &a, &b);
            doucment = doucment.substr(a, b);
            cout << doucment << endl;
            break;
        case 3:
            scanf("%d ", &a);
            cin >> str;
            doucment.insert(a, str);
            cout << doucment << endl;
            break;
        case 4:
            cin >> str;
            int pos = doucment.find(str);
            printf("%d\n",pos);
        }
    }
    return 0;
}