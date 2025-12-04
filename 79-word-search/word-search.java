class Solution {
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        if (m == 0) return false;
        int n = board[0].length;
        int L = word.length();
        if (L == 0) return true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, int i, int j, String word, int idx) {
        int m = board.length;
        int n = board[0].length;

        // Out of bounds or mismatch
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word.charAt(idx)) {
            return false;
        }

        // Matched the last character
        if (idx == word.length() - 1) {
            return true;
        }

        // Mark current cell as visited
        char orig = board[i][j];
        board[i][j] = '#';

        // Explore all 4 directions
        boolean found = dfs(board, i + 1, j, word, idx + 1)
                     || dfs(board, i - 1, j, word, idx + 1)
                     || dfs(board, i, j + 1, word, idx + 1)
                     || dfs(board, i, j - 1, word, idx + 1);

        // Backtrack
        board[i][j] = orig;
        return found;
    }
}
