/*
Title: N-Queens Problem using Backtracking
Contributor: https://github.com/fatimaa-dev

Description:
1. The N-Queens puzzle involves placing N queens on an N×N chessboard
   such that no two queens attack each other.
2. Queens can attack horizontally, vertically, and diagonally.
3. This solution uses backtracking with three key constraint arrays:
   - columns[]: tracks which columns are occupied
   - diag1[]: tracks occupied diagonals (top-left to bottom-right)
   - diag2[]: tracks occupied diagonals (top-right to bottom-left)
4. For position (row, col):
   - Column check: columns[col]
   - Diagonal 1 check: diag1[row + col]
   - Diagonal 2 check: diag2[row - col + n - 1]
5. We place queens row by row, backtracking when no valid position exists.
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Backtracking function to solve N-Queens
void dfs(vector<vector<string>> &ans, vector<string> &temp, vector<bool> &columns,
         vector<bool> &diag1, vector<bool> &diag2, int row, int n) {
    
    // Base case: all queens are placed successfully
    if (row == n) {
        cout << "Solution found! Adding to results." << endl;
        ans.push_back(temp);
        return;
    }

    cout << "Trying to place queen in row " << row << endl;

    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        // Check if position is safe (not attacked by any previous queen)
        if (!columns[col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
            cout << "  Placing queen at (" << row << ", " << col << ")" << endl;

            // Mark this column and diagonals as occupied
            columns[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

            // Create row string with queen at current column
            string s(n, '.');
            s[col] = 'Q';
            temp.push_back(s);

            // Recursively place queens in next row
            dfs(ans, temp, columns, diag1, diag2, row + 1, n);

            // Backtrack: remove queen and unmark constraints
            cout << "  Backtracking from (" << row << ", " << col << ")" << endl;
            temp.pop_back();
            columns[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }
}

// Main function to solve N-Queens puzzle
vector<vector<string>> solveNQueens(int n) {
    // Initialize constraint arrays
    vector<bool> columns(n, false);           // Track occupied columns
    vector<bool> diag1(2 * n - 1, false);     // Track occupied / diagonals
    vector<bool> diag2(2 * n - 1, false);     // Track occupied \ diagonals
    
    vector<vector<string>> ans;               // Store all solutions
    vector<string> temp;                      // Store current board configuration

    cout << "Starting N-Queens solver for n = " << n << "\n" << endl;
    dfs(ans, temp, columns, diag1, diag2, 0, n);
    
    return ans;
}

// Helper function to print a board configuration
void printBoard(const vector<string> &board) {
    for (const string &row : board) {
        cout << row << endl;
    }
    cout << endl;
}

int main() {
    int n = 4; // Example input
    
    cout << "=== N-Queens Problem (n = " << n << ") ===\n" << endl;
    
    vector<vector<string>> solutions = solveNQueens(n);
    
    cout << "\n=== All Solutions ===\n" << endl;
    cout << "Total solutions found: " << solutions.size() << "\n" << endl;
    
    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << (i + 1) << ":" << endl;
        printBoard(solutions[i]);
    }

    return 0;
}

/*
Example Output (for n = 4):
=== N-Queens Problem (n = 4) ===

Starting N-Queens solver for n = 4

Trying to place queen in row 0
  Placing queen at (0, 0)
Trying to place queen in row 1
  Placing queen at (1, 2)
Trying to place queen in row 2
  Backtracking from (1, 2)
  Placing queen at (1, 3)
... (detailed backtracking steps)
Solution found! Adding to results.
...

=== All Solutions ===

Total solutions found: 2

Solution 1:
.Q..
...Q
Q...
..Q.

Solution 2:
..Q.
Q...
...Q
.Q..


Time Complexity: O(N!)
- We try to place queens row by row
- For each row, we have at most N choices
- As we place more queens, available positions decrease

Space Complexity: O(N)
- Recursion depth is N (one for each row)
- Constraint arrays: O(N) for columns, O(2N-1) for each diagonal array

Advantages:
1. Efficient constraint checking using boolean arrays (O(1) per check)
2. Diagonal tracking using mathematical formulas avoids complex checks
3. Backtracking prunes invalid paths early
4. Finds all distinct solutions systematically

Key Insights:
1. Diagonal formulas:
   - Top-left to bottom-right: row + col (constant for same diagonal)
   - Top-right to bottom-left: row - col + (n-1) (constant for same diagonal)
2. By placing queens row by row, we automatically avoid row conflicts
3. Boolean arrays provide O(1) conflict detection
*/