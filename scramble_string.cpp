#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class ScrambleStringSolver {
private:
    string s1;
    string s2;
    int n;

    // memo[i][j][len]
    // -1 = not calculated
    //  0 = false
    //  1 = true
    vector<vector<vector<int>>> memo;

    bool sameSubstring(int i, int j, int len) {
        for (int k = 0; k < len; k++) {
            if (s1[i + k] != s2[j + k]) {
                return false;
            }
        }

        return true;
    }

    bool sameCharacterFrequency(int i, int j, int len) {
        array<int, 26> frequency{};

        for (int k = 0; k < len; k++) {
            frequency[s1[i + k] - 'a']++;
            frequency[s2[j + k] - 'a']--;
        }

        for (int count : frequency) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }

    bool solve(int i, int j, int len) {

        // Already calculated
        if (memo[i][j][len] != -1) {
            return memo[i][j][len] == 1;
        }

        // If both substrings are already equal
        if (sameSubstring(i, j, len)) {
            memo[i][j][len] = 1;
            return true;
        }

        // If character frequencies are different,
        // they cannot be scrambles.
        if (!sameCharacterFrequency(i, j, len)) {
            memo[i][j][len] = 0;
            return false;
        }

        // Try every possible split
        for (int split = 1; split < len; split++) {

            // --------------------------------
            // Case 1: No swap
            //
            // s1 = LEFT | RIGHT
            // s2 = LEFT | RIGHT
            // --------------------------------
            bool noSwap =
                solve(i, j, split) &&
                solve(i + split, j + split, len - split);

            if (noSwap) {
                memo[i][j][len] = 1;
                return true;
            }

            // --------------------------------
            // Case 2: Swap
            //
            // s1 = LEFT | RIGHT
            // s2 = RIGHT | LEFT
            // --------------------------------
            bool swap =
                solve(i, j + len - split, split) &&
                solve(i + split, j, len - split);

            if (swap) {
                memo[i][j][len] = 1;
                return true;
            }
        }

        memo[i][j][len] = 0;
        return false;
    }

public:

    bool isScramble(const string& first, const string& second) {

        // Different lengths cannot be scrambles
        if (first.length() != second.length()) {
            return false;
        }

        s1 = first;
        s2 = second;
        n = static_cast<int>(s1.length());

        // Create DP table
        memo.assign(
            n,
            vector<vector<int>>(
                n,
                vector<int>(n + 1, -1)
            )
        );

        return solve(0, 0, n);
    }
};


// --------------------------------------------------
// Test Functions
// --------------------------------------------------

void runTests() {

    ScrambleStringSolver solver;

    cout << "Running tests...\n\n";

    // Test 1
    cout << "Test 1: great -> rgeat\n";
    cout << "Expected: true\n";
    cout << "Result:   "
         << boolalpha
         << solver.isScramble("great", "rgeat")
         << "\n\n";

    // Test 2
    cout << "Test 2: abcde -> caebd\n";
    cout << "Expected: false\n";
    cout << "Result:   "
         << solver.isScramble("abcde", "caebd")
         << "\n\n";

    // Test 3
    cout << "Test 3: a -> a\n";
    cout << "Expected: true\n";
    cout << "Result:   "
         << solver.isScramble("a", "a")
         << "\n\n";

    // Additional tests
    cout << "Test 4: ab -> ba\n";
    cout << "Expected: true\n";
    cout << "Result:   "
         << solver.isScramble("ab", "ba")
         << "\n\n";

    cout << "Test 5: abc -> def\n";
    cout << "Expected: false\n";
    cout << "Result:   "
         << solver.isScramble("abc", "def")
         << "\n\n";

    cout << "Test 6: abc -> acb\n";
    cout << "Expected: true\n";
    cout << "Result:   "
         << solver.isScramble("abc", "acb")
         << "\n\n";

    cout << "Test 7: hello -> hello\n";
    cout << "Expected: true\n";
    cout << "Result:   "
         << solver.isScramble("hello", "hello")
         << "\n\n";
}


// --------------------------------------------------
// Main Program
// --------------------------------------------------
int main() {

    ScrambleStringSolver solver;

    int choice;

    while (true) {

        cout << "\n=====================================\n";
        cout << "       SCRAMBLE STRING SOLVER\n";
        cout << "=====================================\n";
        cout << "1. Check a string\n";
        cout << "2. Run test cases\n";
        cout << "3. Exit\n";
        cout << "=====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                string s1, s2;

                cout << "\nEnter first string : ";
                cin >> s1;

                cout << "Enter second string: ";
                cin >> s2;

                bool result = solver.isScramble(s1, s2);

                cout << "\n-------------------------------------\n";

                if (result) {
                    cout << "Result: TRUE\n";
                    cout << "\"" << s2
                         << "\" is a scramble of \""
                         << s1 << "\".\n";
                }
                else {
                    cout << "Result: FALSE\n";
                    cout << "\"" << s2
                         << "\" is NOT a scramble of \""
                         << s1 << "\".\n";
                }

                cout << "-------------------------------------\n";

                break;
            }

            case 2: {
                cout << "\n";
                runTests();

                break;
            }

            case 3: {
                cout << "\nThank you for using Scramble String Solver!\n";
                cout << "Exiting program...\n";

                return 0;
            }

            default: {
                cout << "\nInvalid choice!\n";
                cout << "Please enter 1, 2, or 3.\n";

                break;
            }
        }
    }

    return 0;
}