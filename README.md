# COSC 120: Computer Science I

My coursework from **COSC 120: Computer Science I** at Salisbury University (fall 2022), in **C++**.

The course moves from control flow and functions through file I/O, arrays, vectors and pointers, then to structs, classes, operator overloading and recursion.

## Projects

| Folder | Description |
|---|---|
| `Project01`: **Spell checker** | Three spell checkers built on a dictionary file: a single-word checker, a case-insensitive document checker, and *The Ultimate Spell Checker* (case-sensitive). The full document checker flags misspelled words, suggests corrections (swapped adjacent letters, an added or missing letter, or a dictionary word that begins with the misspelling), and lets you accept a suggestion, keep the word or type a new one, then writes the corrected document. |
| `Project02`: **Life expectancy reporter** | Reads a life-expectancy dataset into a vector of structs and produces summary reports |
| `Project03`: **Card deck classes** | `Card` and `Deck` classes, plus a **derangement counter** that simulates shuffles to estimate how often no card ends up in its original position |

## Homework and labs

| Folder | Topics and programs |
|---|---|
| `Lab02`, `Lab03`, `Homework01` | Arithmetic and conditionals: gas mileage, a recipe scaler, BMI, seconds conversion, shipping rates, population growth, a guessing game |
| `Homework02`, `Lab05` | Loops and functions: Caesar cipher, the 3n + 1 (Collatz) sequence, dice-roll simulations, tolerance-based approximation |
| `Homework03`, `Homework04`, `Lab04` | File I/O and strings: min/max from a file, word search and counting, an anagram finder, a word-scramble game, a word processor that counts lines, words and characters |
| `Homework05`, `Lab06`, `Lab07`, `Lab08` | Arrays and vectors: letter and word frequencies, company data analysis, dice-frequency simulation, descriptive statistics for stock data (in three versions: plain, arrays and vectors) |
| `Homework06`, `Homework07` | Applied data processing: class grade projections, a ticket-purchasing system, vector-based data analysis |
| `Homework08`, `Homework09` | Timing experiments; array manipulation with pointers |
| `Homework010`, `Homework011` | Structs and classes: a home-made vector type, a dice-roll tracker, a soccer player record, an `IntList` class |
| `Homework012` | Operator overloading: `IntList` operators, an `IntSet` class, a set-based guessing game |
| `Homework013` | Recursion: palindromes, Pascal's triangle (n choose k), the Q and D sequences, Towers of Hanoi |

Folders ending in `Files` (`HW03Files`, `Lab06Files`, …) hold the input data files for the matching assignment.

## Building

Each program is a standalone `main.cpp`, with any class files beside it:

```bash
cd Project01/TheUltimateSpellChecker
g++ -std=c++17 -o spellcheck *.cpp
./spellcheck
```

## Note

This repository is an archive of completed coursework. It is shared for reference. Please don't submit it as your own work.

**[Kyle Tranfaglia](https://github.com/ktranfaglia1)** · B.S. Computer Science & Data Science, Salisbury University
