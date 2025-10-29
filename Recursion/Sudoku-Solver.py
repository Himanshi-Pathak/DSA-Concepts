"""
Title: Sudoku Solver using Backtracking
Contributor: https://github.com/Nitin-0017

Description:
1. Sudoku is a logic-based puzzle where the goal is to fill a 9×9 grid 
   so that each row, column, and 3×3 subgrid contains all digits from 1 to 9.
2. Empty cells are represented by '.' (dots).
3. The backtracking algorithm works as follows:
      - Find an empty cell.
      - Try placing digits 1 to 9.
      - If the placement is valid, recursively proceed.
      - If a conflict occurs, backtrack and try another digit.
4. The recursion stops when the entire board is filled correctly.
5. This algorithm guarantees a valid solution if one exists.
"""

# Function to solve Sudoku using Backtracking
def solve_sudoku(board):
    # Function to check if placing a digit is valid
    def is_valid(r, c, ch):
        # Check the row
        for i in range(9):
            if board[r][i] == ch:
                return False

        # Check the column
        for i in range(9):
            if board[i][c] == ch:
                return False

        # Check 3x3 subgrid
        start_r, start_c = (r // 3) * 3, (c // 3) * 3
        for i in range(start_r, start_r + 3):
            for j in range(start_c, start_c + 3):
                if board[i][j] == ch:
                    return False

        return True  # Safe placement found

    # Recursive function to fill the Sudoku grid
    def backtrack():
        for r in range(9):
            for c in range(9):
                if board[r][c] == '.':  # Empty cell found
                    for ch in '123456789':  # Try all digits
                        if is_valid(r, c, ch):
                            board[r][c] = ch
                            print(f"Placed {ch} at ({r}, {c})")

                            if backtrack():
                                return True  # Continue solving
                            
                            board[r][c] = '.'  # Undo move
                            print(f"Removed {ch} from ({r}, {c}) (backtrack)")
                    return False  # No valid number found → backtrack
        return True  # Sudoku solved successfully

    # Start solving
    backtrack()


"""
Example Usage:
board = [
    ['5','3','.','.','7','.','.','.','.'],
    ['6','.','.','1','9','5','.','.','.'],
    ['.','9','8','.','.','.','.','6','.'],
    ['8','.','.','.','6','.','.','.','3'],
    ['4','.','.','8','.','3','.','.','1'],
    ['7','.','.','.','2','.','.','.','6'],
    ['.','6','.','.','.','.','2','8','.'],
    ['.','.','.','4','1','9','.','.','5'],
    ['.','.','.','.','8','.','.','7','9']
]

print("Solving Sudoku Puzzle...\n")
solve_sudoku(board)

print("\nSolved Sudoku Grid:")
for row in board:
    print(" ".join(row))
"""

"""
Example Output (Simplified):

Placed 4 at (0, 2)
Placed 6 at (0, 5)
Removed 6 from (0, 5) (backtrack)
Placed 9 at (0, 5)
...
Solved Sudoku Grid:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
"""

"""
Advantages:
1. Demonstrates recursion and backtracking in an easy-to-understand way.
2. Guarantees a valid solution if one exists.
3. Clearly shows step-by-step placements and backtracking.

Disadvantages:
1. Can be slow for complex puzzles with many empty cells.
2. Requires deep recursion for difficult boards.
"""
