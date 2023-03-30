/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:39:14 by atarchou          #+#    #+#             */
/*   Updated: 2023/03/30 01:50:35 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stack>
// #include <cstdlib>
// #include <cstring>
// #include <cctype>
// #include <iostream>
// using namespace std;

// // A class for evaluating RPN expressions
// class RPN_Evaluator {
// public:
//     RPN_Evaluator(const char* expr) : m_expr(expr) {}

//     // Evaluates the expression and returns the result
//     int evaluate() {
//         stack<int> s;
//         int len = strlen(m_expr);
//         for (int i = 0; i < len; i++) {
//             if (isspace(m_expr[i])) {
//                 continue;
//             }
//             char ch = m_expr[i];
//             if (isdigit(ch)) {
//                 int num = ch - '0';
//                 while (i+1 < len && isdigit(m_expr[i+1])) {
//                     num = num * 10 + (m_expr[i+1] - '0');
//                     i++;
//                 }
//                 s.push(num);
//             } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
//                 if (s.size() < 2) {
//                     cerr << "Error: insufficient operands for " << ch << endl;
//                     exit(1);
//                 }
//                 int b = s.top(); s.pop();
//                 int a = s.top(); s.pop();
//                 int result = 0;
//                 switch (ch) {
//                     case '+': result = a + b; break;
//                     case '-': result = a - b; break;
//                     case '*': result = a * b; break;
//                     case '/': result = a / b; break;
//                 }
//                 s.push(result);
//             } else {
//                 cerr << "Error: invalid token " << ch << endl;
//                 exit(1);
//             }
//         }
//         if (s.size() != 1) {
//             cerr << "Error: too many operands" << endl;
//             exit(1);
//         }
//         return s.top();
//     }

// private:
//     const char* m_expr;
// };

// // Main function that reads the input expression and evaluates it
// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         cerr << "Usage: " << argv[0] << " <expression in RPN>" << endl;
//         exit(1);
//     }
//     // Insert spaces between the digits in numbers with more than one digit
//     string expr_with_spaces = "";
//     for (int i = 0; argv[1][i] != '\0'; i++) {
//         if (isdigit(argv[1][i])) {
//             if (i > 0 && isdigit(argv[1][i-1])) {
//                 expr_with_spaces += ' ';
//             }
//         }
//         expr_with_spaces += argv[1][i];
//     }
//     RPN_Evaluator eval(expr_with_spaces.c_str());
//     int result = eval.evaluate();
//     cout << result << endl;
//     return 0;
// }
#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

class Calculator {
public:
    Calculator(string expr) : expr_(expr) {}

    double calculate() {
        stack<double> s;
        int i = 0;
        while (i < expr_.length()) {
            if (isdigit(expr_[i])) {
                double num = 0;
                while (isdigit(expr_[i])) {
                    num = num * 10 + (expr_[i] - '0');
                    i++;
                }
                s.push(num);
            } else if (expr_[i] == '+' || expr_[i] == '-' || expr_[i] == '*' || expr_[i] == '/') {
                if (s.size() < 2) {
                    cout << "Error: insufficient operands for " << expr_[i] << endl;
                    exit(1);
                }
                double op2 = s.top();
                s.pop();
                double op1 = s.top();
                s.pop();
                double result;
                if (expr_[i] == '+') {
                    result = op1 + op2;
                } else if (expr_[i] == '-') {
                    result = op1 - op2;
                } else if (expr_[i] == '*') {
                    result = op1 * op2;
                } else if (expr_[i] == '/') {
                    if (op2 == 0) {
                        cout << "Error: division by zero" << endl;
                        exit(1);
                    }
                    result = op1 / op2;
                }
                s.push(result);
                i++;
            } else if (isspace(expr_[i])) {
                i++;
            } else {
                cout << "Error: invalid token" << endl;
                exit(1);
            }
        }
        if (s.size() != 1) {
            cout << "Error: too many operands" << endl;
            exit(1);
        }
        return s.top();
    }

private:
    string expr_;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <expression>" << endl;
        return 1;
    }
    Calculator calculator(argv[1]);
    cout << calculator.calculate() << endl;
    return 0;
}

