#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

// N-Queens 
vector<vector<string>> nQueensResult;

bool isSafe(vector<int> &pos, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (pos[i] == col || abs(pos[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueens(int row, int n, vector<int> &pos) {
    if (row == n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string s(n, '.');
            s[pos[i]] = 'Q';
            board.push_back(s);
        }
        nQueensResult.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(pos, row, col)) {
            pos[row] = col;
            solveNQueens(row + 1, n, pos);
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    nQueensResult.clear();
    vector<int> pos(n);
    solveNQueens(0, n, pos);
    return nQueensResult;
}

//  Rat in a Maze 
vector<string> ratInMazeResult;

void solveRatMaze(int i, int j, vector<vector<int>> &mat,
                  vector<vector<int>> &vis, int n, string path) {

    if (i == n - 1 && j == n - 1) {
        ratInMazeResult.push_back(path);
        return;
    }

    vis[i][j] = 1;

    if (i + 1 < n && mat[i + 1][j] == 1 && !vis[i + 1][j])
        solveRatMaze(i + 1, j, mat, vis, n, path + "D");

    if (j - 1 >= 0 && mat[i][j - 1] == 1 && !vis[i][j - 1])
        solveRatMaze(i, j - 1, mat, vis, n, path + "L");

    if (j + 1 < n && mat[i][j + 1] == 1 && !vis[i][j + 1])
        solveRatMaze(i, j + 1, mat, vis, n, path + "R");

    if (i - 1 >= 0 && mat[i - 1][j] == 1 && !vis[i - 1][j])
        solveRatMaze(i - 1, j, mat, vis, n, path + "U");

    vis[i][j] = 0;
}

vector<string> ratInMaze(vector<vector<int>> &mat) {
    int n = mat.size();

    if (mat[0][0] == 0)
        return {};

    vector<vector<int>> vis(n, vector<int>(n, 0));
    ratInMazeResult.clear();

    solveRatMaze(0, 0, mat, vis, n, "");

    sort(ratInMazeResult.begin(), ratInMazeResult.end());
    return ratInMazeResult;
}

// Sudoku Solver 
bool isValidSudoku(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValidSudoku(board, i, j, c)) {
                        board[i][j] = c;

                        if (solveSudoku(board))
                            return true;

                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Main
int main() {

    cout << "N-Queens solutions:\n";
    vector<vector<string>> queens = solveNQueens(4);

    for (auto board : queens) {
        for (auto row : board)
            cout << row << endl;
        cout << endl;
    }

    cout << "Rat in Maze paths:\n";
    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {0,1,0,0},
        {1,1,1,1}
    };

    vector<string> paths = ratInMaze(maze);

    for (string s : paths)
        cout << s << " ";
    cout << endl;

    cout << "\nSudoku solution:\n";

    vector<vector<char>> sudoku = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(sudoku);

    for (auto row : sudoku) {
        for (char c : row)
            cout << c;
        cout << endl;
    }

    return 0;
}