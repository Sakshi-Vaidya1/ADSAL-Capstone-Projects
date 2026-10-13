#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int strongPasswordChecker(string password) {
    int n = password.length();

    bool lower = false, upper = false, digit = false;

    for (unsigned char ch : password) {
        if (islower(ch)) lower = true;
        if (isupper(ch)) upper = true;
        if (isdigit(ch)) digit = true;
    }

    int missing = !lower + !upper + !digit;
    int replace = 0, one = 0, two = 0;

    for (int i = 0; i < n;) 
    {
        int j = i;

        while (j < n && password[j] == password[i])
            j++;

        int len = j - i;

        if (len >= 3) {
            replace += len / 3;

            if (len % 3 == 0) one++;
            else if (len % 3 == 1) two++;
        }

        i = j;
    }

    if (n < 6)
        return max(missing, 6 - n);

    if (n <= 20)
        return max(missing, replace);

    int del = n - 20;

    replace -= min(del, one);
    replace -= min(max(0, del - one), two * 2) / 2;
    replace -= max(0, del - one - two * 2) / 3;

    return del + max(missing, replace);
}

void suggestChanges(string password) {
    int n = password.length();

    bool lower = false, upper = false, digit = false;

    for (unsigned char ch : password) {
        if (islower(ch)) lower = true;
        if (isupper(ch)) upper = true;
        if (isdigit(ch)) digit = true;
    }

    cout << "\n--- Greedy Suggestions ---\n";

    if (n < 6)
        cout << "1. Add " << 6 - n
             << " character(s) to reach length 6.\n";
    else if (n > 20)
        cout << "1. Delete " << n - 20
             << " character(s) to reach length 20.\n";
    else
        cout << "1. Password length is valid.\n";

    if (!lower)
        cout << "2. Add at least one lowercase letter (a-z).\n";

    if (!upper)
        cout << "3. Add at least one uppercase letter (A-Z).\n";

    if (!digit)
        cout << "4. Add at least one digit (0-9).\n";

    bool repeated = false;

    for (int i = 0; i < n;) {
        int j = i;

        while (j < n && password[j] == password[i])
            j++;

        int len = j - i;

        if (len >= 3) {
            repeated = true;
            cout << "Repeated sequence '" << password[i]
                 << "' occurs " << len << " times.\n";
            cout << "   Break this sequence by replacing, "
                 << "inserting, or deleting characters.\n";
        }

        i = j;
    }

    if (!repeated)
        cout << "No three consecutive identical characters found.\n";

    cout << "Note: These are suggested actions; apply them "
         << "and check the password again.\n";
}

int main() {
    string password;
    int choice;

    cout << "Enter password: ";
    cin >> password;

    while (true) {
        int changes = strongPasswordChecker(password);

        cout << "\nCurrent password: " << password << '\n';
        cout << "Minimum changes required: " << changes << '\n';

        if (changes == 0) {
            cout << "Your password is strong!\n";
        } else {
            suggestChanges(password);
        }

        cout << "\n1. Enter updated password";
        cout << "\n2. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter updated password: ";
            cin >> password;
        } else if (choice == 2) {
            cout << "Program exited.\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}