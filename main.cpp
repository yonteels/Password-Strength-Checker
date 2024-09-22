#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool hasLowerCase(const string &password) {
    for (char c : password) {
        if (islower(c)) return true;
    }
    return false;
}

bool hasUpperCase(const string &password) {
    for (char c : password) {
        if (isupper(c)) return true;
    }
    return false;
}

bool hasDigit(const string &password) {
    for (char c : password) {
        if (isdigit(c)) return true;
    }
    return false;
}

bool hasSpecialChar(const string &password) {
    const string specialChars = "!@#$%^&*()-_+=<>?";
    for (char c : password) {
        if (specialChars.find(c) != string::npos) return true;
    }
    return false;
}

string checkPasswordStrength(const string &password) {
    int length = password.length();
    
    if (length < 8) {
        return "Weak: Password is too short (minimum 8 characters).";
    }

    bool lower = hasLowerCase(password);
    bool upper = hasUpperCase(password);
    bool digit = hasDigit(password);
    bool special = hasSpecialChar(password);

    if (lower && upper && digit && special) {
        return "Strong: Password meets all requirements.";
    } else if ((lower && upper && digit) || (lower && upper && special) || (upper && digit && special) || (lower && digit && special)) {
        return "Medium: Password could be stronger.";
    } else {
        return "Weak: Password lacks important elements.";
    }
}

int main() {
    string password;
    
    cout << "Enter a password: ";
    cin >> password;
    
    string result = checkPasswordStrength(password);
    cout << result << endl;
    
    return 0;
}
