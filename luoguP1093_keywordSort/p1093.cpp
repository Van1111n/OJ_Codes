#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    int id;
    int chinese;
    int math;
    int english;
};

bool stu_compare(Student a, Student b) {
    int aTotal = a.chinese + a.english + a.math;
    int bTotal = b.chinese + b.english + b.math;
    if (aTotal < bTotal) {
        return false;
    } else if (aTotal > bTotal) {
        return true;
    } else {
        if (a.chinese < b.chinese) {
            return false;
        } else if (a.chinese > b.chinese) {
            return true;
        } else {
            if (a.id > b.id) {
                return false;
            } else {
                return true;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    vector<Student> students(n);
    for (int i=0; i<n; i++){
        students.at(i).id=i+1;
        scanf("%d %d %d", &students.at(i).chinese, &students.at(i).math, &students.at(i).english);
    }
    sort(students.begin(), students.end(), stu_compare);
    for (int i=0; i<5; i++){
        printf("%d %d\n", students.at(i).id, students.at(i).chinese + students.at(i).math + students.at(i).english);
    }
    return 0;
}