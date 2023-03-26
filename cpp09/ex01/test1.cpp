/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atarchou <atarchou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 21:39:14 by atarchou          #+#    #+#             */
/*   Updated: 2023/03/25 23:02:59 by atarchou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <stack>
// #include <cstdlib>
// #include <cstring>

// using namespace std;

// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         cerr << "Error: no input provided." << endl;
//         return 1;
//     }
//     stack<int> s;
//     char* token = strtok(argv[1], " ");
//     while (token != NULL) {
//         if (isdigit(token[0])) {
//             s.push(atoi(token));
//         } else if (strlen(token) == 1 && strchr("+-*/", token[0]) != NULL) {
//             if (s.size() < 2) {
//                 cerr << "Error: not enough operands." << endl;
//                 return 1;
//             }
//             int b = s.top();
//             s.pop();
//             int a = s.top();
//             s.pop();
//             switch(token[0]) {
//                 case '+':
//                     s.push(a + b);
//                     break;
//                 case '-':
//                     s.push(a - b);
//                     break;
//                 case '*':
//                     s.push(a * b);
//                     break;
//                 case '/':
//                     if (b == 0) {
//                         cerr << "Error: division by zero." << endl;
//                         return 1;
//                     }
//                     s.push(a / b);
//                     break;
//                 default:
//                     cerr << "Error: invalid operator." << endl;
//                     return 1;
//             }
//         } else {
//             cerr << "Error: invalid operand." << endl;
//             return 1;
//         }
//         token = strtok(NULL, " ");
//     }
//     if (s.size() == 1) {
//         cout << s.top() << endl;
//         return 0;
//     } else if (s.size() == 0) {
//         cerr << "Error: no operands." << endl;
//         return 1;
//     } else {
//         cerr << "Error: too many operands." << endl;
//         return 1;
//     }
// }

#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Error: no input provided." << endl;
        return 1;
    }
    stack<int> s;
    char* token = strtok(argv[1], " ");
    int num_operands = 0;
    int num_operators = 0;
    while (token != NULL) {
        if (isdigit(token[0])) {
            s.push(atoi(token));
            num_operands++;
        } else if (strlen(token) == 1 && strchr("+-*/", token[0]) != NULL) {
            if (num_operands < 2) {
                cerr << "Error: not enough operands." << endl;
                return 1;
            }
            num_operands--;
            int b = s.top();
            s.pop();
            num_operands--;
            int a = s.top();
            s.pop();
            switch(token[0]) {
                case '+':
                    s.push(a + b);
                    break;
                case '-':
                    s.push(a - b);
                    break;
                case '*':
                    s.push(a * b);
                    break;
                case '/':
                    if (b == 0) {
                        cerr << "Error: division by zero." << endl;
                        return 1;
                    }
                    s.push(a / b);
                    break;
                default:
                    cerr << "Error: invalid operator." << endl;
                    return 1;
            }
            num_operators++;
        } else {
            cerr << "Error: invalid operand." << endl;
            return 1;
        }
        token = strtok(NULL, " ");
    }
    if (num_operands == 1 && num_operators > 0) {
        cout << s.top() << endl;
        return 0;
    } else if (num_operands == 0 && num_operators == 0) {
        cerr << "Error: no input provided." << endl;
        return 1;
    } else {
        cerr << "Error: invalid input." << endl;
        return 1;
    }
}

