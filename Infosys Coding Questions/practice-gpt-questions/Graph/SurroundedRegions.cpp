
#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col,
         vector<vector<char>>& board,
         vector<vector<int>>& vis) {
    // Write your DFS logic

    int n=board.size();
    int m=board[0].size();

    vis[row][col]=1;
    int delrow[]={-1, 0, +1, 0};
    int delcol[]={0, +1, 0, -1};

    for(int i=0; i<4; i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  
            && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow, ncol, board, vis);
            }
    }

}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    if (board.empty() || board[0].empty()) return;

    // Step 1: Traverse boundary cells

    //first row and last row
    for(int i=0; i<m; i++){
        //first row
        if(!vis[0][i] && board[0][i]=='O'){
            dfs(0, i, board, vis);
        }
        //last col
        if(!vis[n-1][i] && board[n-1][i] == 'O'){
            dfs(n-1, i, board, vis);
        }
    }

    //first col, last col
    for(int j=0; j<n; j++){
        //first row
        if(!vis[j][0] && board[j][0]=='O'){
            dfs(j, 0, board, vis);
        }
        
        if(!vis[j][m-1] && board[j][m-1] == 'O'){
            dfs(j, m-1, board, vis);
        }
    }

    // Step 2: Run DFS from boundary 'O' cells

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         if(board[i][j]=='O' && !vis[i][j]){
    //             board[i][j]='X';
    //         }
    //     }
    // }

    // Step 3: Capture surrounded regions
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j]=='O' && !vis[i][j]){
                board[i][j]='X';
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    solve(board);

    cout<<"********************************************************\n";

    for (auto& row : board) {
        for (int j = 0; j < m; j++) {
            cout << row[j] << (j + 1 == m ? '\n' : ' ');
        }
    }

    return 0;
}
