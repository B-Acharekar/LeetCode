#include <vector>
#include <string>
#include <functional>
#include <iostream>

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        function<bool(int,int,int)>dfs = [&](int r,int c,int index){
            if(index == word.size()) return true;
            if(r<0||c<0||r>=rows||c>=cols) return false;
            if(board[r][c] != word[index]) return false;

            char temp = board[r][c];
            board[r][c] = '#';
            bool found = dfs(r + 1, c, index + 1) ||
                         dfs(r - 1, c, index + 1) ||
                         dfs(r, c + 1, index + 1) ||
                         dfs(r, c - 1, index + 1);
            
            board[r][c] = temp;
            return found;
        };

        for(int r =0;r<rows; ++r){
            for(int c =0; c<cols;++c){
                if(board[r][c]==word[0]){
                    if (dfs(r,c,0)) return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";

    cout << (sol.exist(board, word) ? "True" : "False") << endl;

    return 0;
}