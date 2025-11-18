# Introduction to Object Oriented Programming
## Module 1 – Assignment #1
### XYZ Bank ATM Program

**Group Members:**
- Dain Thorpe
- Shanique Wisdom
- Joan Johnson-Brown
- Dante Graham
- Pasha Pinnock

**Lecturer:** Doron Williams  
**Date:** November 2025

### Description
Console ATM program in C++ using a class (`Account`) with encapsulation, constructor validation, and menu navigation.

### Features
- `Account` class with private `balance`
- Constructor validates initial balance (>= 1000 else sets to 0 and warns)
- `Deposit(amount)`, `Withdraw(amount)`, `GetBalance()`
- `do...while` loop + `switch` menu (Check, Deposit, Withdraw, Exit)
- Clear messages and simple validation

### How to Run
```bash
cd /c/Users/Anonymous/Documents/IntroOOP_Assignment1_Group_Dain_Shanique_Joan
g++ -std=c++20 -Wall main.cpp -o atm.exe
./atm.exe

