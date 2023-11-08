//
// Created by User on 11/8/2023.
//

#ifndef WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_5_H
#define WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_5_H
#include <iostream>
using namespace std;
class TowerOfHanoi {
public:
    void moveDisks(int N, char from, char to, char aux) {
        if (N == 1) {
            cout << "Move disk 1 from peg " << from << " to peg " << to << endl;
            return;
        }
        moveDisks(N - 1, from, aux, to);
        cout << "Move disk " << N << " from peg " << from << " to peg " << to << endl;
        moveDisks(N - 1, aux, to, from);
    }
};

int main() {
    int N;
    cout << "Enter the number of disks: ";
    cin >> N;
    TowerOfHanoi toh;
    toh.moveDisks(N, 'A', 'C', 'B');
    return 0;
}

#endif //WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_5_H
