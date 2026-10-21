
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string exp;
    stack<int> st;

    cout << "Enter postfix expression: ";
    cin >> exp;

    for (char c : exp) {
        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            if (st.size() < 2) {
                cout << "Invalid expression\n";
                return 0;
            }

            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cout << "Division by zero\n";
                        return 0;
                    }
                    st.push(a / b);
                    break;
                default:
                    cout << "Invalid operator\n";
                    return 0;
            }
        }
    }

    if (st.size() == 1)
        cout << "Result: " << st.top() << endl;
    else
        cout << "Invalid expression\n";

    return 0;
}
