//
// Created by User on 11/8/2023.
//

#ifndef WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_4_H
#define WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_4_H
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class ContainerMover {
public:
    ContainerMover(int N) : N(N), stacks(N) {}

    void moveContainers(int from, int to) {
        int container = stacks[from].top();
        stacks[from].pop();
        stacks[to].push(container);
        cout << from + 1 << " " << to + 1 << endl;
    }

    void performMoves() {
        bool possible = true;
        for (int i = 0; i < N; i++) {
            if (!stacks[i].empty() && stacks[i].top() != i + 1) {
                int j;
                for (j = i + 1; j < N; j++) {
                    if (stacks[j].empty() || stacks[j].top() != i + 1) {
                        break;
                    }
                }
                if (j == N) {
                    while (j > i) {
                        moveContainers(j - 1, j);
                        j--;
                    }
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            for (int i = 0; i < N; i++) {
                while (!stacks[i].empty()) {
                    if (stacks[i].top() == i + 1) {
                        stacks[i].pop();
                    } else {
                        int moveTo = stacks[i].top() - 1;
                        moveContainers(i, moveTo);
                    }
                }
            }
        } else {
            cout << "0" << endl;
        }
    }

    void readInputs() {
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int type;
                cin >> type;
                stacks[i].push(type);
            }
        }
    }

private:
    int N;
    vector<stack<int>> stacks;
};

int main() {
    int N;
    cin >> N;
    ContainerMover mover(N);
    mover.readInputs();
    mover.performMoves();
    return 0;
}

#endif //WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_4_H
