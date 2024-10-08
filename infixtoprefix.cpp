#include<iostream>
#include<stack>
#include<string>
#include<algorithm> // for reversal
using namespace std;

// Function to determine precedence of operators
int precedence(char c) {
    if (c == '^') {
        return 3;
    } else if ((c == '/') || (c == '*')) {
        return 2;
    } else if ((c == '+') || (c == '-')) {
        return 1;
    } else {
        return -1;
    }
}

// Function to reverse the expression and swap parentheses
void reverseExpression(string &s) {
    reverse(s.begin(), s.end()); // Reverse the entire string

    // Swap '(' with ')' and vice versa
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }
}

// Function to convert infix to prefix
void infixToPrefix(string &s, stack<char> &st, string &ans) {
    int n = s.size();
    int i = 0;

    while (i < n) {
        // Operands (letters or digits)
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        }
        // Open bracket
        else if (s[i] == '(') {
            st.push(s[i]);
        }
        // Close bracket
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }
        // Operators
        else {
            while (!st.empty() && precedence(st.top()) > precedence(s[i])) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]); // Push the current operator
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
}

int main() {
    string s = "(A+B)*C-D+F";
    stack<char> st;
    string ans = "";

    // Step 1: Reverse the infix expression and swap parentheses
    reverseExpression(s);

    // Step 2: Convert to postfix
    infixToPrefix(s, st, ans);

    // Step 3: Reverse the postfix result to get the prefix expression
    reverse(ans.begin(), ans.end());

    // Output the prefix expression
    cout << "Prefix Expression: " << ans << endl;

    return 0;
}
