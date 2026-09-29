# 🔀 Scramble String Solver

![C++](https://img.shields.io/badge/C%2B%2B-17-blue?style=for-the-badge&logo=cplusplus)
![Algorithm](https://img.shields.io/badge/Algorithm-Dynamic%20Programming-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)

A clean and interactive **C++17 implementation of the Scramble String problem** using **recursive dynamic programming, memoization, and character-frequency pruning**.

---

## 📌 Table of Contents

- [Overview](#-overview)
- [Problem Statement](#-problem-statement)
- [Example](#-example)
- [Features](#-features)
- [Algorithm](#-algorithm)
- [How It Works](#-how-it-works)
- [Flowchart](#-flowchart)
- [Complexity Analysis](#-complexity-analysis)
- [Project Structure](#-project-structure)
- [Installation](#-installation)
- [Usage](#-usage)
- [Sample Output](#-sample-output)
- [Testing](#-testing)
- [Technologies Used](#-technologies-used)
- [Learning Outcomes](#-learning-outcomes)
- [Future Improvements](#-future-improvements)
- [License](#-license)

---

## 📖 Overview

The **Scramble String Solver** determines whether one string can be transformed into another using a recursive scrambling process.

The project demonstrates several important computer science concepts:

- Recursion
- Dynamic Programming
- Memoization
- Divide and Conquer
- String Processing
- State-based Problem Solving
- Optimization through Pruning

The application provides an interactive command-line interface where users can check whether two strings are scramble strings.

---

## 🧩 Problem Statement

Given two strings `s1` and `s2` of the same length, determine whether `s2` is a scrambled version of `s1`.

A string can be scrambled using the following process:

1. If the string has length `1`, stop.
2. Split the string into two non-empty substrings.
3. Either:
   - Keep the two substrings in the same order, or
   - Swap the two substrings.
4. Recursively apply the same process to both substrings.

### Example

```text
s1 = "great"
s2 = "rgeat"