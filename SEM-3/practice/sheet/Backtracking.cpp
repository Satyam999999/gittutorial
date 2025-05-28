// Problem Type	Description
// 1	N-Queens	Place N queens on an N×N chessboard such that no two queens threaten each other.
// 2	Sudoku Solver	Fill a 9×9 grid such that each row, column, and 3×3 box contains digits 1–9.
// 3	Rat in a Maze / Maze Solver	Find all paths from the top-left to the bottom-right in a maze.
// 4	Permutations of a string/array	Generate all permutations of a given array or string.
// 5	Subsets (Power Set)	Generate all subsets of a set.
// 6	Combination Sum / Target Sum	Find all combinations of numbers that sum up to a target.
// 7	Palindrome Partitioning	Partition a string into palindromic substrings.
// 8	Word Search (Grid Search)	Search for a word in a 2D character grid.
// 9	Knight’s Tour Problem	Move a knight on a chessboard such that it visits every square exactly once.
// 10	Binary Strings Without Consecutive 1s	Generate binary strings of length N without consecutive 1s.
// 11	M-Coloring Problem (Graph coloring)	Color the graph with at most M colors without adjacent nodes sharing a color.
// 12	Tug of War / Balanced Partitioning	Split a set into two subsets with minimum difference in their sums.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

///////////////////////////////////////////////////////////////
// 1. N-Queens Problem
///////////////////////////////////////////////////////////////

bool isSafeNQueen(vector<string>& board, int row, int col, int n) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void solveNQueensHelper(int row, int n, vector<string>& board, vector<vector<string>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafeNQueen(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueensHelper(row + 1, n, board, solutions);
            board[row][col] = '.';
        }
    }
}

void solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<string> board(n, string(n, '.'));
    solveNQueensHelper(0, n, board, solutions);
    cout << "N-Queens solutions:\n";
    for (auto& sol : solutions) {
        for (auto& row : sol) cout << row << endl;
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////
// 2. Sudoku Solver
///////////////////////////////////////////////////////////////

bool isValidSudoku(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c || board[row][i] == c ||
            board[3*(row/3)+i/3][3*(col/3)+i%3] == c)
            return false;
    }
    return true;
}

bool solveSudokuHelper(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValidSudoku(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudokuHelper(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudokuHelper(board);
    cout << "Solved Sudoku:\n";
    for (auto& row : board) {
        for (char c : row) cout << c << " ";
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////
// 3. Permutations
///////////////////////////////////////////////////////////////

void permuteHelper(vector<int>& nums, int l, vector<vector<int>>& res) {
    if (l == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = l; i < nums.size(); i++) {
        swap(nums[l], nums[i]);
        permuteHelper(nums, l + 1, res);
        swap(nums[l], nums[i]);
    }
}

void generatePermutations(vector<int> nums) {
    vector<vector<int>> res;
    permuteHelper(nums, 0, res);
    cout << "All permutations:\n";
    for (auto& p : res) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////
// 4. Subsets
///////////////////////////////////////////////////////////////

void subsetHelper(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& res) {
    res.push_back(current);
    for (int i = index; i < nums.size(); i++) {
        current.push_back(nums[i]);
        subsetHelper(nums, i + 1, current, res);
        current.pop_back();
    }
}

void generateSubsets(vector<int> nums) {
    vector<vector<int>> res;
    vector<int> current;
    subsetHelper(nums, 0, current, res);
    cout << "All subsets:\n";
    for (auto& s : res) {
        for (int x : s) cout << x << " ";
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////
// 5. Rat in a Maze
///////////////////////////////////////////////////////////////

bool isSafeMaze(int x, int y, vector<vector<int>>& maze, int n, vector<vector<int>>& visited) {
    return (x >= 0 && y >= 0 && x < n && y < n && maze[x][y] == 1 && !visited[x][y]);
}

void solveMazeHelper(int x, int y, vector<vector<int>>& maze, int n, vector<vector<int>>& visited, string path, vector<string>& res) {
    if (x == n - 1 && y == n - 1) {
        res.push_back(path);
        return;
    }
    visited[x][y] = 1;
    if (isSafeMaze(x + 1, y, maze, n, visited)) solveMazeHelper(x + 1, y, maze, n, visited, path + 'D', res);
    if (isSafeMaze(x, y - 1, maze, n, visited)) solveMazeHelper(x, y - 1, maze, n, visited, path + 'L', res);
    if (isSafeMaze(x, y + 1, maze, n, visited)) solveMazeHelper(x, y + 1, maze, n, visited, path + 'R', res);
    if (isSafeMaze(x - 1, y, maze, n, visited)) solveMazeHelper(x - 1, y, maze, n, visited, path + 'U', res);
    visited[x][y] = 0;
}

void ratInMaze(vector<vector<int>> maze) {
    int n = maze.size();
    vector<vector<int>> visited(n, vector<int>(n, 0));
    vector<string> res;
    solveMazeHelper(0, 0, maze, n, visited, "", res);
    cout << "Paths in maze:\n";
    for (auto& path : res) cout << path << endl;
}

///////////////////////////////////////////////////////////////
// 6. Palindrome Partitioning
///////////////////////////////////////////////////////////////

bool isPalindrome(string& s, int l, int r) {
    while (l < r) {
        if (s[l++] != s[r--]) return false;
    }
    return true;
}

void palindromePartitionHelper(string& s, int index, vector<string>& path, vector<vector<string>>& res) {
    if (index == s.length()) {
        res.push_back(path);
        return;
    }
    for (int i = index; i < s.length(); i++) {
        if (isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));
            palindromePartitionHelper(s, i + 1, path, res);
            path.pop_back();
        }
    }
}

void palindromePartitioning(string s) {
    vector<vector<string>> res;
    vector<string> path;
    palindromePartitionHelper(s, 0, path, res);
    cout << "Palindrome partitions:\n";
    for (auto& p : res) {
        for (string& s : p) cout << s << " ";
        cout << endl;
    }
}

///////////////////////////////////////////////////////////////
// 7. Word Search in Grid
///////////////////////////////////////////////////////////////

bool searchWord(vector<vector<char>>& board, string& word, int x, int y, int index, vector<vector<bool>>& visited) {
    if (index == word.length()) return true;
    int n = board.size(), m = board[0].size();
    if (x < 0 || y < 0 || x >= n || y >= m || board[x][y] != word[index] || visited[x][y]) return false;

    visited[x][y] = true;
    bool found = searchWord(board, word, x + 1, y, index + 1, visited) ||
                 searchWord(board, word, x - 1, y, index + 1, visited) ||
                 searchWord(board, word, x, y + 1, index + 1, visited) ||
                 searchWord(board, word, x, y - 1, index + 1, visited);
    visited[x][y] = false;
    return found;
}

bool existWord(vector<vector<char>>& board, string word) {
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (searchWord(board, word, i, j, 0, visited))
                return true;
    return false;
}

///////////////////////////////////////////////////////////////
// 8. M Coloring (Graph Coloring)
// Color graph with M colors so that no two adjacent nodes have same color
///////////////////////////////////////////////////////////////

bool isSafeColor(int node, int color[], bool graph[101][101], int n, int c) {
    for (int k = 0; k < n; k++)
        if (graph[node][k] && color[k] == c)
            return false;
    return true;
}

bool graphColoringHelper(bool graph[101][101], int m, int color[], int i, int n) {
    if (i == n) return true;
    for (int c = 1; c <= m; c++) {
        if (isSafeColor(i, color, graph, n, c)) {
            color[i] = c;
            if (graphColoringHelper(graph, m, color, i + 1, n)) return true;
            color[i] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    int color[101] = {0};
    return graphColoringHelper(graph, m, color, 0, n);
}

///////////////////////////////////////////////////////////////
// MAIN FUNCTION
///////////////////////////////////////////////////////////////

int main() {
    solveNQueens(4);

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

    generatePermutations({1, 2, 3});
    generateSubsets({1, 2, 3});

    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    ratInMaze(maze);

    palindromePartitioning("aab");

    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << "Word Search (ABCCED): " << (existWord(board, "ABCCED") ? "Found" : "Not Found") << endl;

    bool graph[101][101] = {0};
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[0][2] = graph[2][0] = 1;
    cout << "Graph Coloring possible (m=3): " << (graphColoring(graph, 3, 3) ? "Yes" : "No") << endl;

    return 0;
}
