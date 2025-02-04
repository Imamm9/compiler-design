#include <iostream>
#include <string>

using namespace std;

bool isValidVariableName(const string& name) {
    if (!(name[0] == '_' || (name[0] >= 'a' && name[0] <= 'z') || (name[0] >= 'A' && name[0] <= 'Z'))) {
        return false;
    }
    for (size_t i = 1; i < name.length(); i++) {
        if (!(name[i] == '_' || (name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9'))) {
            return false;
        }
    }
    return true;
}

bool checkValidExpression(const string& expr) {
    int opCount = 0;
    size_t eqPos = expr.find('=');
    if (eqPos == string::npos || eqPos == 0 || eqPos == expr.length() - 1) return false;

    string leftSide = expr.substr(0, eqPos);
    if (!isValidVariableName(leftSide)) return false;

    string rightSide = expr.substr(eqPos + 1);
    char validOps[] = {'+', '-', '*', '/'};

    for (char c : rightSide) {
        for (char op : validOps) {
            if (c == op) {
                opCount++;
            }
        }
    }

    if (opCount == 0 || opCount > 2) return false;

    size_t start = 0;
    while (start < rightSide.length()) {
        size_t end = rightSide.find_first_of("+-*/", start);
        if (end == string::npos) {
            end = rightSide.length();
        }
        string token = rightSide.substr(start, end - start);
        if (!isValidVariableName(token)) {
            return false;
        }
        start = end + 1;
    }

    return true;
}

bool checkPrefixPostfix(const string& expr) {
    size_t len = expr.length();
    if (len <= 2) return false;

    if (isalnum(expr[0]) && expr[len - 1] == expr[len - 2] && (expr[len - 1] == '+' || expr[len - 1] == '-')) {
        return true;
    }
    if (expr[0] == expr[1] && (expr[0] == '+' || expr[0] == '-') && isalnum(expr[2])) {
        return true;
    }
    return false;
}

int main() {
    string expr;

    cout << "Enter expression  ";
    getline(cin, expr);
    cout << expr << " is " << (checkValidExpression(expr) ? "valid" : "invalid") << " expression.\n";

    cout << "Enter postfix/prefix expression (e.g., X++, ++X): ";
    getline(cin, expr);
    cout << expr << " is " << (checkPrefixPostfix(expr) ? "valid" : "invalid") << " expression.\n";

    return 0;
}
