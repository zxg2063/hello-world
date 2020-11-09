/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (30.51%)
 * Total Accepted:    257.6K
 * Total Submissions: 843.1K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (0 == word.length()) {
            return true;
        }
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                if (board[i][j] == word[0]) {
                    if (check(i, j, word.substr(1), board))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

    bool check(int beginX, int beginY, string word, vector<vector<char>> board) {
        if (0 == word.length()) {
            return true;
        }

        board[beginX][beginY] = ' ';
        //check up
        if (0 < beginX && board[beginX-1][beginY] == word[0]) {
            if (check(beginX-1, beginY, word.substr(1), board)) {
                return true;
            }
        }
        //check down
        if (board.size() > beginX+1 && board[beginX+1][beginY] == word[0]) {
            if (check(beginX+1, beginY, word.substr(1), board)) {
                return true;
            }
        }
        //check left
        if (0 < beginY && board[beginX][beginY-1] == word[0]) {
            if (check(beginX, beginY-1, word.substr(1), board)) {
                return true;
            }
        }
        //check right
        if (board[beginX].size() > beginY+1 && board[beginX][beginY+1] == word[0]) {
            if (check(beginX, beginY+1, word.substr(1), board)) {
                return true;
            }
        }

        return false;
    }
};

