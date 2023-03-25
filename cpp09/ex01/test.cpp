#include <iostream>
#include <stack>
#include <string>
#include <sstream>

bool isOperator(const std::string& token) {
    return token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos;
}

bool isNumber(const std::string& token) {
    std::istringstream iss(token);
    double dummy;
    return iss >> dummy && iss.eof();
}

double performOperation(double op1, double op2, char op) {
    switch(op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
    }
    return 0;
}

double evaluateRPN(const std::string& expression) {
    std::stack<double> st;

    std::istringstream iss(expression);
    std::string token;
    while(iss >> token) {
        if(isNumber(token)) {
            st.push(std::stod(token));
        } else if(isOperator(token)) {
            if(st.size() < 2) {
                std::cout << "Error: not enough operands for " << token << " operator." << std::endl;
                return 0;
            }
            double op2 = st.top();
            st.pop();
            double op1 = st.top();
            st.pop();
            st.push(performOperation(op1, op2, token[0]));
        } else {
            std::cout << "Error: invalid token " << token << std::endl;
            return 0;
        }
    }
    if(st.size() != 1) {
        std::cout << "Error: too many operands." << std::endl;
        return 0;
    }
    return st.top();
}

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Usage: RPN \"expression\"" << std::endl;
        return 0;
    }
    double result = evaluateRPN(argv[1]);
    if(result != 0) {
        std::cout << result << std::endl;
    }
    return 0;
}
