//
// Created by User on 11/8/2023.
//

#ifndef WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_3_H
#define WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_3_H
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
class PostfixEvaluator {
public:
    int evaluatePostfix(const string& exp) {
        stack<int> st;
        for (int i = 0; i < exp.size(); ++i) {
            if (isdigit(exp[i]))
                st.push(exp[i] - '0');
            else {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();
                switch (exp[i]) {
                    case '+':
                        st.push(val2 + val1);
                        break;
                    case '-':
                        st.push(val2 - val1);
                        break;
                    case '*':
                        st.push(val2 * val1);
                        break;
                    case '/':
                        st.push(val2 / val1);
                        break;
                }
            }
        }
        return st.top();
    }
};

int main() {
    string exp;
    cout << "Enter the postfix expression: ";
    cin >> exp;

    PostfixEvaluator evaluator;
    int result = evaluator.evaluatePostfix(exp);
    cout << "The result of the postfix expression is: " << result;

    return 0;
}

#endif //WEEK_4_ASSIGNMENT_LIFO_FIFO_DURDANA4_TASK_3_H
