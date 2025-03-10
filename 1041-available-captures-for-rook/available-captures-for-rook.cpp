class Solution {
public:
    int numRookCaptures(std::vector<std::vector<char>>& board) {
        int rookRow = -1;
        int rookCol = -1;

        // Find the rook's position
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                if (board[i][j] == 'R') {
                    rookRow = i;
                    rookCol = j;
                    break;
                }
            }
            if (rookRow != -1) {
                break;
            }
        }

        int captures = 0;

        // Check in all four directions: up, down, left, right
        // Up
        for (int i = rookRow - 1; i >= 0; --i) {
            if (board[i][rookCol] == 'p') {
                captures++;
                break;
            } else if (board[i][rookCol] == 'B') {
                break;
            }
        }

        // Down
        for (int i = rookRow + 1; i < 8; ++i) {
            if (board[i][rookCol] == 'p') {
                captures++;
                break;
            } else if (board[i][rookCol] == 'B') {
                break;
            }
        }

        // Left
        for (int j = rookCol - 1; j >= 0; --j) {
            if (board[rookRow][j] == 'p') {
                captures++;
                break;
            } else if (board[rookRow][j] == 'B') {
                break;
            }
        }

        // Right
        for (int j = rookCol + 1; j < 8; ++j) {
            if (board[rookRow][j] == 'p') {
                captures++;
                break;
            } else if (board[rookRow][j] == 'B') {
                break;
            }
        }

        return captures;
    }
};