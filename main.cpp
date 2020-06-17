// Student ID: 2031611


#include <iostream>
#include <ctime>
#include "readSudoku.hpp"
#include "solverBacktracking.hpp"

int main() {
    bruteF arr;
    // Read files.
    arr = readFile("sudoku_puzzle.txt");

    // If puzzle valid then solve using backtracking.
    if (checkValidity(arr)) {

        //Print initial Sudoku puzzle;
        printPuzzle(arr);

        //Solve the puzzle using backtracking method and then print the solution.
        clock_t start{clock()}; // clock starts

        backtracking(arr); // Solve the puzzle.

        clock_t end{clock()}; // clock ends

        clock_t elapsed = end - start; // time difference

        // Print time converted to milliseconds.
        std::cout << "Brute force (backtracking) solver took " << 1000*elapsed/CLOCKS_PER_SEC
                << ' ' <<"ms" << std::endl;

    }else{
        // If not puzzle invalid then exit.
        exit(-1);
    }

    return 0;
}