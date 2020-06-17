// Student ID: 2031611
#ifndef SUDOKU_READSUDOKU_HPP
#define SUDOKU_READSUDOKU_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <array>
#define size 9 // can be changed easily for different size of sudoku.


struct bruteF{
    int myArray[size*size];
    int puzzle[size][size];
    int numbersRead;
    int count;
    int zeroArray[size*size - 17][2]; // because min 17 clues
};

// Read Sudoku puzzle from file, return false if unsuccessful.
bruteF readFile(const std::string &x);

// Print the Sudoku puzzle.
void printPuzzle(bruteF &var);

// Check Sudoku puzzle's solvable, return false if less than 17.
bool checkValidity(bruteF &var);

// Check Sudoku puzzle's rules, return false if rules violated.
bool checkRules(bruteF &var);

// Return empty cell's coordinates and count.
bruteF zeroPos(bruteF &var);



#endif //SUDOKU_READSUDOKU_HPP
