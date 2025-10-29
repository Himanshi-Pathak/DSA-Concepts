"""
Title: N-Queens Problem using Backtracking
Contributor: https://github.com/Nitin-0017

Description:
1. The N-Queens problem is a classic backtracking problem where we must place
   N queens on an N×N chessboard such that no two queens threaten each other.
2. This means:
      - No two queens share the same row.
      - No two queens share the same column.
      - No two queens share the same diagonal.
3. We use recursion and backtracking to explore all valid placements.
4. The algorithm places a queen in each row and recursively checks for safety.
5. If a placement leads to a conflict, we backtrack and try a new position.
"""

# Function to solve the N-Queens problem
def solveNQueens(n):
    # Initialize the chessboard with '.'
    board = [["."] * n for _ in range(n)]
    solutions = []  # To store all valid board configurations

    # Function to check if placing a queen at (row, col) is safe
    def isSafe(row, col):
        # Check vertically upward
        i, j = row, col
        while i >= 0:
            if board[i][j] == "Q":
                return False
            i -= 1

        # Check left diagonal
        i, j = row, col
        while i >= 0 and j >= 0:
            if board[i][j] == "Q":
                return False
            i -= 1
            j -= 1

        # Check right diagonal
        i, j = row, col
        while i >= 0 and j < n:
            if board[i][j] == "Q":
                return False
            i -= 1
            j += 1

        return True  # Safe position found

    # Recursive function to try placing queens row by row
    def solve(row):
        # Base case: all queens are placed
        if row == n:
            # Add a deep copy of the current valid configuration
            solutions.append([''.join(r) for r in board])
            return

        # Try placing a queen in each column for the current row
        for col in range(n):
            if isSafe(row, col):
                board[row][col] = "Q"  # Place queen
                print(f"Placed Q at ({row}, {col})")
                solve(row + 1)          # Move to next row
                board[row][col] = "."   # Backtrack
                print(f"Removed Q from ({row}, {col}) (backtrack)")

    # Start from the first row
    solve(0)
    return solutions


"""
Example Output (for n = 4):

Solving 4-Queens Problem:

Placed Q at (0, 1)
Placed Q at (1, 3)
Placed Q at (2, 0)
Placed Q at (3, 2)
Removed Q from (3, 2) (backtrack)
Removed Q from (2, 0) (backtrack)
... etc

All possible solutions:

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

Advantages:
1. Demonstrates recursion and backtracking clearly.
2. Efficiently finds all valid configurations for N queens.
3. Excellent for understanding constraint satisfaction problems.

Disadvantages:
1. Computationally expensive for large N (exponential time).
2. Requires careful handling of recursive calls and backtracking.
"""
