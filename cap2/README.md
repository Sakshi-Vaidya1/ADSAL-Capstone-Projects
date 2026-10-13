# 🔐 Strong Password Checker Using C++

## 📌 Project Overview

The **Strong Password Checker** is a C++ console-based application that evaluates password strength based on length, character variety, and consecutive repeated characters.

The program calculates the minimum number of changes required to make a password strong. It also provides greedy suggestions to help users improve their passwords.

Users can enter an updated password and check it again until they choose to exit the program.

## 🎯 Objectives

- Check whether a password satisfies basic strength requirements.
- Verify the presence of lowercase letters, uppercase letters, and digits.
- Detect three or more consecutive identical characters.
- Calculate the minimum changes required to make a password strong.
- Provide suggestions for adding, deleting, or replacing characters.
- Allow users to recheck an updated password interactively.

## ✨ Features

- **Password Length Validation:** Checks whether the password length is between 6 and 20 characters.
- **Character Variety Check:** Identifies missing lowercase letters, uppercase letters, and digits.
- **Repeated Character Detection:** Detects sequences such as `aaa`, `BBBB`, or `1111`.
- **Minimum Change Calculation:** Uses a greedy algorithm to calculate the minimum required changes.
- **Greedy Suggestions:** Displays recommended actions to improve password strength.
- **Interactive Menu:** Allows users to enter an updated password or exit the application.
- **Real-Time Rechecking:** Evaluates the updated password after every submission.

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Concepts:** Strings, loops, conditional statements, functions, greedy algorithms, and character handling.
- **Libraries:**
  - `iostream` — Input and output operations.
  - `string` — Password storage and manipulation.
  - `algorithm` — Maximum and minimum operations.
  - `cctype` — Character classification functions.

## 📋 Password Requirements

The program considers the following rules when checking a password:

| Rule | Requirement |
|---|---|
| Minimum length | 6 characters |
| Maximum length | 20 characters |
| Lowercase letter | At least one (`a-z`) |
| Uppercase letter | At least one (`A-Z`) |
| Digit | At least one (`0-9`) |
| Repeated characters | No three or more consecutive identical characters |

**Note:** The program checks these specific rules. It does not check for special characters, dictionary words, or whether the password has appeared in a data breach.

## ⚙️ How the Program Works

1. The user enters a password.
2. The program checks the password length.
3. It identifies missing lowercase letters, uppercase letters, and digits.
4. It scans the password to identify consecutive repeated characters.
5. It calculates the minimum number of changes required using a greedy algorithm.
6. It displays the result and suggests possible improvements.
7. The user can enter an updated password to check again or exit the program.

## 🧠 Algorithm Used

The program uses a **Greedy Algorithm** to calculate the minimum changes required.

- **Step 1:** Count the total number of characters in the password.
- **Step 2:** Count the missing character categories.
- **Step 3:** Find consecutive sequences of identical characters.
- **Step 4:** If the password is shorter than 6 characters, calculate the changes needed to meet the minimum length and character requirements.
- **Step 5:** If the password length is between 6 and 20 characters, calculate the replacements required to break repeated sequences.
- **Step 6:** If the password exceeds 20 characters, calculate the required deletions first and use them strategically to reduce repeated sequences.
- **Step 7:** Return the minimum number of changes and display improvement suggestions.

## ▶️ How to Run the Project

### 1. Clone the Repository

```bash
git clone <your-repository-url>
```

### 2. Open the Project Folder

```bash
cd <your-project-folder>
```

### 3. Compile the Program

Using GCC or MinGW:

```bash
g++ main.cpp -o password_checker
```

### 4. Run the Program

On Windows:

```bash
password_checker.exe
```

On Linux or macOS:

```bash
./password_checker
```

**Prerequisite:** A C++ compiler such as GCC, MinGW, or an equivalent compiler must be installed.

## 💻 Sample Output

```text
Enter password: abc

Current password: abc
Minimum changes required: 3

--- Greedy Suggestions ---
1. Add 3 character(s) to reach length 6.
2. Add at least one uppercase letter (A-Z).
3. Add at least one digit (0-9).
No three consecutive identical characters found.
Note: These are suggested actions; apply them and check the password again.

1. Enter updated password
2. Exit
Enter choice: 1
Enter updated password: Abc123

Current password: Abc123
Minimum changes required: 0
Your password is strong!

1. Enter updated password
2. Exit
Enter choice: 2
Program exited.
```

## ⏱️ Time and Space Complexity

Let `n` be the length of the password.

| Operation | Complexity |
|---|---|
| Checking character categories | O(n) |
| Detecting repeated sequences | O(n) |
| Calculating minimum changes | O(n) |
| Suggesting improvements | O(n) |
| Overall time complexity per check | **O(n)** |
| Auxiliary space complexity | **O(1)** |

The program uses a constant number of counters and Boolean variables, excluding the storage required for the input password.

## 📂 Project Structure

```text
Strong-Password-Checker/
│
├── main.cpp
└── README.md
```

## 🚀 Future Enhancements

- Add support for special characters.
- Provide a password strength score.
- Suggest a stronger replacement password.
- Add a graphical user interface.
- Include checks for common or compromised passwords.
- Improve suggestions to show specific character replacements or deletions.

## 🎓 Learning Outcomes

Through this project, I learned how to:

- Work with strings and character-handling functions in C++.
- Apply greedy algorithms to solve an optimization problem.
- Analyze consecutive character sequences.
- Calculate minimum changes under multiple constraints.
- Develop an interactive menu-driven console application.
- Analyze time and space complexity.

