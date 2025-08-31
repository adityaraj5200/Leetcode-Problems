// Time Complexity: O(9^m), where m = number of empty cells
// (each empty cell can branch up to 9 choices, but pruning reduces this drastically)
// Space Complexity: O(81 + 9*10*3) ≈ O(1) (constant, since Sudoku is fixed 9x9)

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // initialize tracking arrays
        rows.assign(9, vector<bool>(10, false));
        cols.assign(9, vector<bool>(10, false));
        boxes.assign(9, vector<bool>(10, false));

        // pre-fill with existing digits
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    rows[i][num] = cols[j][num] = boxes[boxIndex(i, j)][num] = true;
                }
            }
        }
        solve(board);
    }

private:
    vector<vector<bool>> rows, cols, boxes;

    int boxIndex(int row, int col) {
        return (row / 3) * 3 + (col / 3);
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (int num = 1; num <= 9; num++) {
                        if (!rows[row][num] && !cols[col][num] && !boxes[boxIndex(row, col)][num]) {
                            // place number
                            board[row][col] = num + '0';
                            rows[row][num] = cols[col][num] = boxes[boxIndex(row, col)][num] = true;

                            if (solve(board)) return true;

                            // backtrack
                            board[row][col] = '.';
                            rows[row][num] = cols[col][num] = boxes[boxIndex(row, col)][num] = false;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};
