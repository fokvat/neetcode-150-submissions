class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, vector<char>> row ;
        unordered_map<int, vector<char>> column ;
        unordered_map<int, vector<char>> grid ;

        for(int i=0; i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == '.') continue;

                if(find(row[i].begin(), row[i].end(), board[i][j]) != row[i].end()) return false;
                if(find(column[j].begin(), column[j].end(), board[i][j]) != column[j].end()) return false;
                int gridVal = (i/3) * 3 + j /3;
                if(find(grid[gridVal].begin(), grid[gridVal].end(), board[i][j]) != grid[gridVal].end()) return false;
                
                row[i].push_back(board[i][j]);
                column[j].push_back(board[i][j]);
                grid[gridVal].push_back(board[i][j]);
            }
        }

        return true;
        
    }
};
