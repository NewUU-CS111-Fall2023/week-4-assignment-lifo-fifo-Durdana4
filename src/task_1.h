#ifndef WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_1_H
#define WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_1_H

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int value) {
        Node* temp = new Node();
        if (!temp) {
            cout << "Heap Overflow" << endl;
            exit(1);
        }
        temp->data = value;
        temp->next = top;
        top = temp;
    }

    void pop() {
        if (top == NULL) {
            cout << "Underflow" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
    }

    int topElement() {
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }
};
#endif //WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_1_H
