
#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col,
        vector<vector<int>>&ans,
         vector<vector<int>>& image,
         int originalColor, int newColor) {
    // Write your DFS logic

    int n=image.size();
    int m=image[0].size();

    ans[row][col]=newColor;
    
    int delrow[]={-1, 0, +1, 0};
    int delcol[]={0, +1, 0, -1};  

    for(int i=0; i<4; i++){

        int nrow = row+delrow[i];
        int ncol = col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && image[nrow][ncol]==originalColor
            && ans[nrow][ncol] == originalColor ){
                dfs(nrow, ncol, ans, image, originalColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(
    vector<vector<int>>& image,
    int sr, int sc, int newColor) {

    // Write your logic here
    vector<vector<int>>ans= image;
    int n=image.size();
    int m=image[0].size();

    int originalColor = image[sr][sc];
    if (originalColor==newColor){
        return image;
    }  
    dfs(sr, sc, ans, image, originalColor, newColor);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;

    image = floodFill(image, sr, sc, newColor);

    for (auto& row : image) {
        for (int j = 0; j < m; j++) {
            cout << row[j] << (j + 1 == m ? '\n' : ' ');
        }
    }

    return 0;
}
