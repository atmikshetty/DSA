void dfs(int row, int col, vector<vector<int>> &image, vector<vector<int>> &ans, 
int delRow[], int delCol[], int initialColor, int newColor){
    ans[row][col] = newColor;
    int n  = image.size();
    int m = image[0].size();
    for(int i=0;i<4;i++){ // only compare with 4 elements adjacent
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == initialColor &&
        ans[nrow][ncol] != newColor){
            dfs(nrow,ncol,image,ans,delRow,delCol,initialColor,newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int n, int m, int x, int y, int p) {
    // Using DFS
    int initialColor = image[x][y];
    vector<vector<int>> &ans = image;
    int delRow[] = {-1,0,+1,0};
    int delCol[] = {0,+1,0,-1};
    dfs(x,y,image,ans,delRow,delCol,initialColor,p);
    return ans;
}