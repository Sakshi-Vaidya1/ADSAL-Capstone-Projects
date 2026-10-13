# LeetCode 1255 - Maximum Score Words Formed by Letters

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![Algorithm](https://img.shields.io/badge/Algorithm-Branch%20and%20Bound-orange)
![LeetCode](https://img.shields.io/badge/LeetCode-1255-yellow)
![Status](https://img.shields.io/badge/Status-Completed-success)

## 📌 Project Overview

This project implements **LeetCode 1255 - Maximum Score Words Formed by Letters**
using the **Branch and Bound algorithm** in C++.

The objective is to select a valid subset of words that can be formed using
the available letters while maximizing the total score.

Each word can be selected at most once, and each letter can only be used as
many times as it appears in the available letters.

The project is implemented as an **interactive command-line application**
with custom input support and predefined test cases.

---

## 🎯 Problem Statement

Given:

- A list of words
- A collection of available letters
- A score associated with each character from `a` to `z`

Find the **maximum possible score** obtainable by selecting a valid subset
of the given words.

A word can only be selected if all the characters required to form that word
are available.

It is not necessary to use all available letters.

### Example

```text
words = ["dog", "cat", "dad", "good"]

letters = ["a", "a", "c", "d", "d", "d", "g", "o", "o"]