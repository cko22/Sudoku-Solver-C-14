// Student ID: 2031611
#include <iostream>
#include <string>
#include "readSudoku.hpp"
#include <cmath>


bruteF readFile(const std::string &x) {
    bruteF var;
    std::ifstream myFile{x}; // Input text file.

    // Error check to make sure file is opened properly.
    if (!myFile.is_open()) {
        std::cout << "Error opening " << x << std::endl;
        exit (1);
    }
    std::cout << x << " file read successful!" << std::endl;

    // Read integers from the file and store them in an array.
    var.numbersRead = 0;
    while (myFile >> var.myArray[var.numbersRead]){
        ++var.numbersRead;
    }

    // Check if 81 integers were read.
    if (size*size != var.numbersRead){
        std::cout << "Invalid puzzle!" << std::endl;
        exit(-1);
    }

    // Check if 8 distinct clues are given.
    int distinct{1};
    // Pick all elements one by one
    for (int i = 1; i < var.numbersRead; ++i) {
        int j{0};
        for (j = 0; i>j; ++j) {
            if (var.myArray[i] == var.myArray[j]){
                break;
            }
        }
        // If not printed earlier, then print it
        if (i == j) {
            distinct++;
        }
    }
    std::cout << distinct << " distinct clues are given"<< std::endl;
    /* No. of distinct values must be greater
     * than (size of sudoku) - 1 + 1(+1 to exclude 0)
     */
    if (size-1+1 > distinct){
        std::cout << "Sudoku Not Proper!" << std::endl;
        exit(-1);
    }

    // Sort them into Sudoku form.
    for (int row{0}; size > row; ++row){
        for (int col{0}; size > col; ++col){
            var.puzzle[row][col] = var.myArray[col + size*row];
        }
    }
    return var;
}

void printPuzzle(bruteF &var){
    // Loop through the whole Sudoku puzzle and print each value.
    std::cout << "_______________________________" << std::endl;
    for (int row{0}; size > row; ++row){
        if (3 == row || 6 == row){
            std::cout <<  "-------------------------------" << std::endl;
        }
        for (int col{0}; size > col; ++col){
            std::cout << var.puzzle[row][col] << "  ";
            if (2 == col || 5 == col){
                std::cout <<  "|  ";
            }
        }
        std::cout << std::endl;
    }
}

bool checkValidity(bruteF &var) {
    // Check if the puzzle is solvable (at least 17 clues).
    int count{0};
    for (int b{0}; size*size > b; ++b) {
        // Get the non-empty values.
        if (0 != var.myArray[b]) {
            count++;
        } else {
            continue;
        }
    }
    // If less than 17 clues, not solvable.
    if (17 > count) {
        std::cout << "The Sudoku puzzle is not solvable!" << std::endl;
        return false;
    }
    std::cout << "The number of clues given: " << count << std::endl;
    return checkRules(var); // Check if the imported puzzle violates the rules.

}

bool checkRules(bruteF &var){
    // Row, column and nonet (3x3 region) check.
    for (int i{0}; size > i; ++i){
        for (int j{0}; size > j; ++j){
            for (int k = j + 1; size > k; ++k){
                //Check for same number in the same row.
                if(0 != var.puzzle[i][j] && var.puzzle[i][j] == var.puzzle[i][k]){
                    return false;
                }
                //Check for same number in the same column.
                if (0 != var.puzzle[j][i] && var.puzzle[j][i] == var.puzzle[k][i]){
                    return false;
                }
                // Check for each regions (3x3 cells).
                int x = j % 3 + (i % 3) * 3;
                int y = j / 3 + (i / 3) * 3;
                int x_k = k % 3 + (i % 3) * 3;
                int y_k = k / 3 + (i / 3) * 3;
                if (0 != var.puzzle[x][y] && var.puzzle[x][y] == var.puzzle[x_k][y_k]){
                    return false;
                }
            }
        }
    }
    return true;
}

bruteF zeroPos(bruteF &var){
    var.count = 0; // initialise
    for (int row{0}; size > row; ++row) {
        for (int col{0}; size > col; ++col) {
            // If empty, store coordinates.
            if (0 == var.puzzle[row][col]) {
                var.zeroArray[var.count][0] = row;
                var.zeroArray[var.count][1] = col;
                ++var.count; // count empty cells
            }
        }
    }
    return var;
}


