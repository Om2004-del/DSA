class Solution {
public: 
    void dfs(vector<vector<char>>& board, int r, int c){
        int n = board.size();
        int m = board[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m|| board[r][c] != 'O'){
            return;
        }
        board[r][c] = '#';
        dfs(board, r - 1, c); // up
        dfs(board, r + 1, c); // down
        dfs(board, r, c - 1); // left
        dfs(board, r, c + 1); // right

    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0 ; i < n ; i++){
            if(board[i][0]=='O'){
                dfs(board , i , 0);
            }
            if(board[i][m-1]=='O'){
                dfs(board , i, m-1);
            }
        }
        for(int j = 0 ; j < m ; j++){
            if(board[0][j]=='O'){
                dfs(board,0,j);
            }
            if(board[n-1][j]=='O'){
                dfs(board,n-1,j);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};