// Student ID: 2031611

#include "solverBacktracking.hpp"
#include "readSudoku.hpp"


bool backtracking(bruteF &var1){
    bruteF var = var1;
    bruteF zero = zeroPos(var); // For checking zero positions each recursive call.

    // If the number of zero position is zero, the puzzle is solved, return true.
    if (0 == zero.count){
        std::cout << std::endl;
        std::cout << "------------SOLVED-------------" << std::endl;
        printPuzzle(var);
        return true;
    }
    // Try integer 1-9
    for (int num{1}; 10 > num; ++num){
        var.puzzle[zero.zeroArray[0][0]][zero.zeroArray[0][1]] = num;
        if (checkRules(var)) {
            // recursive call
            if (backtracking(var)) {
                return true;
            }
            // reset cell to empty
            var.puzzle[zero.zeroArray[0][0]][zero.zeroArray[0][1]] = 0;
        }
    }
    return false;
}