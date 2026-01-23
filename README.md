# Math Quiz Game (C++)

A console-based Math Quiz Game built using C++, allowing players to choose difficulty levels and math operation types.
The game generates random questions, provides instant feedback, and displays a performance summary at the end.

## Features
- Difficulty levels: Easy, Medium, Hard, or Mixed
- Operation types: Addition, Subtraction, Multiplication, Division, or Mixed
- Random question generation based on selected difficulty
- Instant feedback for each answer
- Final results summary (Pass / Fail)
- Console color feedback for correct and incorrect answers

## Technologies Used
- Language: C++
- Programming Concepts: Structured Programming, Enums, Random Number Generation
- Environment: Console Application
- Compiler: g++ or any modern C++ compiler

## How to Run
```bash
git clone https://github.com/shehabaalfariee-developer/Math-Game-cpp.git
cd Math-Game-cpp
g++ main.cpp -o math_quiz
./math_quiz

WELCOME TO MATH QUIZ
===================
How Many Questions Do You Want To Answer? 3
Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? 2
Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ? 5

Question [1/3]
12
8 +
20
Correct Answer :-)

Question [2/3]
48
12 /
5
Wrong Answer :-(
The Right Answer is : 4

Question [3/3]
6
5 *
30
Correct Answer :-)

Final Result Is: PASS :-)
Right Answers : 2
Wrong Answers : 1
