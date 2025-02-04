#include <iostream>
#include <string>

int performOperation(int a, int b, char op) {
    switch (op) {
        case '@': return a + b;
        case '#': return a - b;
        case '&': return a * b;
        case '$': return a / b;
        default: throw std::invalid_argument("Invalid operator");
    }
}

int getPrecedence(char op) {
    switch (op) {
        case '@': return 1;
        case '#': return 1;
        case '&': return 2;
        case '$': return 2;
        default: return 0;
    }
}

int evaluateExpression(const std::string& expression) {
    int num1 = 0, num2 = 0, result = 0;
    char op = 0;
    bool operatorFound = false;

    for (size_t i = 0; i < expression.length(); ++i) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            if (!operatorFound) {
                num1 = num1 * 10 + (expression[i] - '0');
            } else {
                num2 = num2 * 10 + (expression[i] - '0');
            }
        } else {
            if (operatorFound) {
                result = performOperation(num1, num2, op);
                num1 = result;
                num2 = 0;
            }
            op = expression[i];
            operatorFound = true;
        }
    }

    if (operatorFound) {
        result = performOperation(num1, num2, op);
    }

    return result;
}

int main() {
    std::string expression;
    std::cout << "Enter the expression: ";
    std::cin >> expression;

    try {
        int result = evaluateExpression(expression);
        std::cout << "Output: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
