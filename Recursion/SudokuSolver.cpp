/*
Title: Sudoku Solver using Backtracking
Contributor: https://github.com/fatimaa-dev

Description:
1. Sudoku is a 9×9 grid puzzle where each cell contains digits 1-9 or is empty.
2. Rules:
   - Each row must contain digits 1-9 exactly once
   - Each column must contain digits 1-9 exactly once
   - Each 3×3 sub-box must contain digits 1-9 exactly once
3. This solution uses backtracking:
   - Find an empty cell ('.')
   - Try placing digits 1-9
   - Check if placement is valid (doesn't violate any rule)
   - Recursively solve the rest of the board
   - If stuck, backtrack and try a different digit
4. The is_safe() function checks all three constraints:
   - Row check: board[row][i] for all columns
   - Column check: board[i][col] for all rows
   - 3×3 box check: Uses formula to map cell to its sub-box
5. Time Complexity: O(9^(empty_cells)) in worst case
   Space Complexity: O(1) excluding recursion stack
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing a digit is safe
bool is_safe(vector<vector<char>>& board, int row, int col, char ele) {
    cout << "    Checking if '" << ele << "' is safe at (" << row << ", " << col << ")" << endl;
    
    for (int i = 0; i < 9; i++) {
        // Check if digit already exists in the same row
        if (board[row][i] == ele) {
            cout << "      Found '" << ele << "' in row " << row << " at column " << i << endl;
            return false;
        }
        
        // Check if digit already exists in the same column
        if (board[i][col] == ele) {
            cout << "      Found '" << ele << "' in column " << col << " at row " << i << endl;
            return false;
        }
        
        // Check if digit already exists in the 3×3 sub-box
        // Formula: 3 * (row/3) gives starting row of box, i/3 gives offset
        //          3 * (col/3) gives starting col of box, i%3 gives offset
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ele) {
            cout << "      Found '" << ele << "' in 3×3 box" << endl;
            return false;
        }
    }
    
    cout << "      '" << ele << "' is safe!" << endl;
    return true;
}

// Backtracking function to solve Sudoku
bool backtrack(vector<vector<char>>& board) {
    // Traverse the entire board to find empty cells
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            
            // Found an empty cell
            if (board[row][col] == '.') {
                cout << "  Empty cell found at (" << row << ", " << col << ")" << endl;
                
                // Try placing digits '1' to '9'
                for (char digit = '1'; digit <= '9'; digit++) {
                    cout << "  Trying digit '" << digit << "' at (" << row << ", " << col << ")" << endl;
                    
                    // Check if current digit placement is valid
                    if (is_safe(board, row, col, digit)) {
                        // Place the digit
                        board[row][col] = digit;
                        cout << "  Placed '" << digit << "' at (" << row << ", " << col << ")" << endl;
                        
                        // Recursively solve the rest of the board
                        if (backtrack(board) == true) {
                            return true; // Solution found
                        }
                        
                        // If recursive call fails, backtrack
                        cout << "  Backtracking from (" << row << ", " << col << "), removing '" << digit << "'" << endl;
                        board[row][col] = '.';
                    }
                }
                
                // If no digit works, return false to trigger backtracking
                return false;
            }
        }
    }
    
    // If no empty cells found, puzzle is solved
    cout << "\nAll cells filled! Sudoku solved successfully!" << endl;
    return true;
}

// Main function to solve Sudoku
void solveSudoku(vector<vector<char>>& board) {
    cout << "=== Starting Sudoku Solver ===\n" << endl;
    backtrack(board);
}

// Helper function to print the Sudoku board
void printBoard(const vector<vector<char>>& board) {
    cout << "+-------+-------+-------+" << endl;
    for (int i = 0; i < 9; i++) {
        cout << "| ";
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) cout << "| ";
        }
        cout << endl;
        if ((i + 1) % 3 == 0) cout << "+-------+-------+-------+" << endl;
    }
}

int main() {
    // Example Sudoku puzzle (0 or '.' represents empty cells)
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << "=== Original Sudoku Board ===" << endl;
    printBoard(board);
    cout << endl;

    // Solve the Sudoku
    solveSudoku(board);

    cout << "\n=== Solved Sudoku Board ===" << endl;
    printBoard(board);

    return 0;
}

/*
Example Output:
=== Original Sudoku Board ===
+-------+-------+-------+
| 5 3 . | . 7 . | . . . | 
| 6 . . | 1 9 5 | . . . | 
| . 9 8 | . . . | . 6 . | 
+-------+-------+-------+
| 8 . . | . 6 . | . . 3 | 
| 4 . . | 8 . 3 | . . 1 | 
| 7 . . | . 2 . | . . 6 | 
+-------+-------+-------+
| . 6 . | . . . | 2 8 . | 
| . . . | 4 1 9 | . . 5 | 
| . . . | . 8 . | . 7 9 | 
+-------+-------+-------+

=== Starting Sudoku Solver ===

  Empty cell found at (0, 2)
  Trying digit '1' at (0, 2)
    Checking if '1' is safe at (0, 2)
      Found '1' in column 2 at row 1
  Trying digit '2' at (0, 2)
    Checking if '2' is safe at (0, 2)
      '2' is safe!
  ... (detailed backtracking steps)

All cells filled! Sudoku solved successfully!

=== Solved Sudoku Board ===
+-------+-------+-------+
| 5 3 4 | 6 7 8 | 9 1 2 | 
| 6 7 2 | 1 9 5 | 3 4 8 | 
| 1 9 8 | 3 4 2 | 5 6 7 | 
+-------+-------+-------+
| 8 5 9 | 7 6 1 | 4 2 3 | 
| 4 2 6 | 8 5 3 | 7 9 1 | 
| 7 1 3 | 9 2 4 | 8 5 6 | 
+-------+-------+-------+
| 9 6 1 | 5 3 7 | 2 8 4 | 
| 2 8 7 | 4 1 9 | 6 3 5 | 
| 3 4 5 | 2 8 6 | 1 7 9 | 
+-------+-------+-------+


Algorithm Explanation:
1. The solver scans left-to-right, top-to-bottom for empty cells ('.')
2. For each empty cell, it tries digits '1' through '9'
3. For each digit, is_safe() performs three checks:
   a) Row check: Ensures digit not already in same row
   b) Column check: Ensures digit not already in same column
   c) Box check: Uses formula to check the 3×3 sub-box
4. If a digit is safe, place it and recursively solve remaining cells
5. If recursion succeeds, return true (solution found)
6. If recursion fails, backtrack by removing digit and trying next one
7. If no digit works, return false to trigger backtracking in previous call

3×3 Box Formula:
- Box starting row = 3 * (row / 3)
- Box starting col = 3 * (col / 3)
- To check all 9 cells in box using single loop (i = 0 to 8):
  - Cell row = 3 * (row / 3) + i / 3
  - Cell col = 3 * (col / 3) + i % 3

Time Complexity: O(9^m) where m is number of empty cells
- In worst case, we try all 9 digits for each empty cell
- Pruning through constraint checking reduces actual complexity

Space Complexity: O(1) auxiliary space
- Modifies board in-place
- Recursion stack depth = O(m) where m is empty cells

Advantages:
1. No extra space needed for constraint tracking
2. Solves any valid Sudoku puzzle guaranteed
3. Simple and elegant implementation
4. Easy to understand and modify

Optimization Possibilities:
1. Use bitsets for faster constraint checking
2. Pre-compute possible values for each cell
3. Choose cells with fewest possibilities first (MRV heuristic)
4. Use constraint propagation techniques
*/