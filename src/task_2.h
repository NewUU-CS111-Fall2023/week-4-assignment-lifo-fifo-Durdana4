//
// Created by User on 11/8/2023.
//

#ifndef WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_2_H
#define WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_2_H
#include <iostream>
#include <vector>

using namespace std;

class PathChecker {
public:
    PathChecker(int l, const vector<int>& s) : l(l), s(s) {}

    void checkPath() {
        vector<int> tup = {0};
        vector<int> tr2 = {0};

        for (int i = 0; i < l; i++) {
            while (tup.back() == tr2.back() + 1) {
                tr2.push_back(tup.back());
                tup.pop_back();
            }
            if (s[i] == tr2.back() + 1) {
                tr2.push_back(s[i]);
            } else {
                tup.push_back(s[i]);
            }
        }

        while (tup.back() == tr2.back() + 1) {
            tr2.push_back(tup.back());
            tup.pop_back();
        }

        if (tr2.back() == l) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

private:
    int l;
    vector<int> s;
};

int main() {
    int l;
    cin >> l;
    vector<int> s(l);
    for (int i = 0; i < l; i++) {
        cin >> s[i];
    }

    PathChecker pathChecker(l, s);
    pathChecker.checkPath();
    return 0;
}

#endif //WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_2_H
