
#include <iostream>
#include <string>
using namespace std;

bool isReservedKeyword(string str) {
    string reserved[] = {"int", "float", "static", "public", "string"};
    for (int i = 0; i < 5; i++) {
        if (str == reserved[i]) {
            return true;
        }
    }
    return false;
}

bool isValidVariableName(string varName) {
    if (varName.empty() || varName.at(0) >= '0' && varName.at(0) <= '9') return false;

    for (int i = 0; i < varName.length(); i++) {
        char ch = varName.at(i);
        cout << "Extracted character at index " << i << ": '" << ch << "'" << endl;

        if (!( (ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') ||
               (ch >= 'a' && ch <= 'z') || ch == '_')) {
            return false;
        }
    }

    if (isReservedKeyword(varName)) return false;

    return true;
}

int main() {
    string variableName;
    cout << "Enter the variable name: ";
    cin >> variableName;

    cout << (isValidVariableName(variableName) ? "Valid" : "Invalid") << " variable name." << endl;
    return 0;
}

