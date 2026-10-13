#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <limits>

using namespace std;

class MaximumScoreSolver {
private:
    vector<string> words;
    array<int, 26> availableLetters{};
    array<int, 26> letterScore{};

    vector<array<int, 26>> wordFrequency;
    vector<int> wordScore;

    int numberOfWords;
    int bestScore;

    /*
        Calculates the score of one word.
    */
    int calculateWordScore(const string& word) {
        int total = 0;

        for (char ch : word) {
            total += letterScore[ch - 'a'];
        }

        return total;
    }

    /*
        Checks whether a word can be formed using
        the currently available letters.
    */
    bool canFormWord(int index) {
        for (int i = 0; i < 26; i++) {
            if (wordFrequency[index][i] > availableLetters[i]) {
                return false;
            }
        }

        return true;
    }

    /*
        Branch and Bound Upper Bound.

        The upper bound assumes that all remaining
        word scores can potentially be obtained.

        If this upper bound is already <= bestScore,
        the branch cannot produce a better answer,
        so we prune it.
    */
    int calculateUpperBound(int index, int currentScore) {
        int bound = currentScore;

        for (int i = index; i < numberOfWords; i++) {
            bound += wordScore[i];
        }

        return bound;
    }

    /*
        Branch and Bound search.

        At every word we have two choices:

        1. Include the word
        2. Exclude the word

        Branches that cannot improve the current
        best answer are pruned.
    */
    void branchAndBound(int index, int currentScore) {

        // All words have been considered.
        if (index == numberOfWords) {
            bestScore = max(bestScore, currentScore);
            return;
        }

        // Calculate the upper bound for this branch.
        int upperBound = calculateUpperBound(index, currentScore);

        // Branch and Bound pruning.
        if (upperBound <= bestScore) {
            return;
        }

        /*
            Branch 1: Include current word
        */
        if (canFormWord(index)) {

            // Use the letters required by the word.
            for (int i = 0; i < 26; i++) {
                availableLetters[i] -= wordFrequency[index][i];
            }

            branchAndBound(
                index + 1,
                currentScore + wordScore[index]
            );

            // Restore letters after returning.
            for (int i = 0; i < 26; i++) {
                availableLetters[i] += wordFrequency[index][i];
            }
        }

        /*
            Branch 2: Exclude current word
        */
        branchAndBound(index + 1, currentScore);
    }

public:

    /*
        Main solver function.
    */
    int solve(
        const vector<string>& inputWords,
        const vector<char>& letters,
        const vector<int>& score
    ) {
        words = inputWords;
        numberOfWords = static_cast<int>(words.size());
        bestScore = 0;

        availableLetters.fill(0);
        letterScore.fill(0);

        // Store available letters.
        for (char ch : letters) {
            availableLetters[ch - 'a']++;
        }

        // Store character scores.
        for (int i = 0; i < 26; i++) {
            letterScore[i] = score[i];
        }

        wordFrequency.clear();
        wordScore.clear();

        /*
            Precalculate frequency and score
            for every word.
        */
        for (const string& word : words) {

            array<int, 26> frequency{};
            int totalScore = 0;

            for (char ch : word) {
                frequency[ch - 'a']++;
                totalScore += letterScore[ch - 'a'];
            }

            wordFrequency.push_back(frequency);
            wordScore.push_back(totalScore);
        }

        /*
            Sort words by descending score.

            Higher scoring words are considered first,
            which often helps find a good bestScore early
            and therefore improves pruning.
        */
        vector<int> order(numberOfWords);

        for (int i = 0; i < numberOfWords; i++) {
            order[i] = i;
        }

        sort(
            order.begin(),
            order.end(),
            [&](int a, int b) {
                return wordScore[a] > wordScore[b];
            }
        );

        vector<string> sortedWords;
        vector<array<int, 26>> sortedFrequency;
        vector<int> sortedScores;

        for (int index : order) {
            sortedWords.push_back(words[index]);
            sortedFrequency.push_back(wordFrequency[index]);
            sortedScores.push_back(wordScore[index]);
        }

        words = sortedWords;
        wordFrequency = sortedFrequency;
        wordScore = sortedScores;

        /*
            Start Branch and Bound.
        */
        branchAndBound(0, 0);

        return bestScore;
    }
};


/*
    Displays the 26 character scores.
*/
void displayScores(const vector<int>& score) {

    cout << "\nCharacter Scores:\n";

    for (int i = 0; i < 26; i++) {
        cout << static_cast<char>('a' + i)
             << " = "
             << score[i]
             << "    ";

        if ((i + 1) % 6 == 0) {
            cout << '\n';
        }
    }

    cout << '\n';
}


/*
    Runs the LeetCode examples.
*/
void runTests() {

    MaximumScoreSolver solver;

    cout << "\n============================================\n";
    cout << "       RUNNING LEETCODE TEST CASES\n";
    cout << "============================================\n";

    /*
        Test Case 1
    */
    {
        vector<string> words = {
            "dog",
            "cat",
            "dad",
            "good"
        };

        vector<char> letters = {
            'a', 'a', 'c', 'd', 'd',
            'd', 'g', 'o', 'o'
        };

        vector<int> score = {
            1, 0, 9, 5, 0, 0, 3, 0, 0, 0,
            0, 0, 0, 0, 2, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0
        };

        int result = solver.solve(words, letters, score);

        cout << "\nTest Case 1\n";
        cout << "Expected: 23\n";
        cout << "Result:   " << result << '\n';
        cout << "Status:   "
             << (result == 23 ? "PASS" : "FAIL")
             << '\n';
    }

    /*
        Test Case 2
    */
    {
        vector<string> words = {
            "xxxz",
            "ax",
            "bx",
            "cx"
        };

        vector<char> letters = {
            'z', 'a', 'b', 'c',
            'x', 'x', 'x'
        };

        vector<int> score = {
            4, 4, 4, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 5, 0, 10
        };

        int result = solver.solve(words, letters, score);

        cout << "\nTest Case 2\n";
        cout << "Expected: 27\n";
        cout << "Result:   " << result << '\n';
        cout << "Status:   "
             << (result == 27 ? "PASS" : "FAIL")
             << '\n';
    }

    /*
        Test Case 3
    */
    {
        vector<string> words = {
            "leetcode"
        };

        vector<char> letters = {
            'l', 'e', 't', 'c', 'o', 'd'
        };

        vector<int> score = {
            0, 0, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 1, 0, 0, 1, 0, 0, 0, 0, 1,
            0, 0, 0, 0, 0, 0
        };

        int result = solver.solve(words, letters, score);

        cout << "\nTest Case 3\n";
        cout << "Expected: 0\n";
        cout << "Result:   " << result << '\n';
        cout << "Status:   "
             << (result == 0 ? "PASS" : "FAIL")
             << '\n';
    }

    cout << "\n============================================\n";
}


/*
    Takes custom input from the user.
*/
void runCustomProblem() {

    MaximumScoreSolver solver;

    int numberOfWords;

    cout << "\n============================================\n";
    cout << "       MAXIMUM SCORE WORDS SOLVER\n";
    cout << "           BRANCH AND BOUND\n";
    cout << "============================================\n";

    cout << "\nEnter number of words: ";
    cin >> numberOfWords;

    if (numberOfWords <= 0) {
        cout << "Number of words must be positive.\n";
        return;
    }

    vector<string> words(numberOfWords);

    cout << "\nEnter the words:\n";

    for (int i = 0; i < numberOfWords; i++) {
        cout << "Word " << i + 1 << ": ";
        cin >> words[i];
    }

    int numberOfLetters;

    cout << "\nEnter number of available letters: ";
    cin >> numberOfLetters;

    if (numberOfLetters <= 0) {
        cout << "Number of letters must be positive.\n";
        return;
    }

    vector<char> letters(numberOfLetters);

    cout << "\nEnter available letters:\n";

    for (int i = 0; i < numberOfLetters; i++) {
        cout << "Letter " << i + 1 << ": ";
        cin >> letters[i];

        if (letters[i] < 'a' || letters[i] > 'z') {
            cout << "Only lowercase English letters are allowed.\n";
            return;
        }
    }

    vector<int> score(26);

    cout << "\nEnter score for each character:\n";

    for (int i = 0; i < 26; i++) {

        cout << static_cast<char>('a' + i)
             << ": ";

        cin >> score[i];

        if (score[i] < 0) {
            cout << "Score cannot be negative.\n";
            return;
        }
    }

    displayScores(score);

    int result = solver.solve(words, letters, score);

    cout << "\n============================================\n";
    cout << "              FINAL RESULT\n";
    cout << "============================================\n";

    cout << "Maximum Score: " << result << '\n';

    cout << "============================================\n";
}


/*
    Main menu.
*/
int main() {

    int choice;

    while (true) {

        cout << "\n\n";
        cout << "============================================\n";
        cout << "   LEETCODE 1255 - MAXIMUM SCORE WORDS\n";
        cout << "             BRANCH AND BOUND\n";
        cout << "============================================\n";
        cout << "1. Solve custom problem\n";
        cout << "2. Run LeetCode test cases\n";
        cout << "3. Exit\n";
        cout << "============================================\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {

            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "\nInvalid input. Please enter 1, 2, or 3.\n";
            continue;
        }

        switch (choice) {

            case 1:
                runCustomProblem();
                break;

            case 2:
                runTests();
                break;

            case 3:
                cout << "\nThank you for using the solver!\n";
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "\nInvalid choice.\n";
                cout << "Please enter 1, 2, or 3.\n";
        }
    }

    return 0;
}