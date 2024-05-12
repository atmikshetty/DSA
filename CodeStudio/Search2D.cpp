bool searchMatrix(vector<vector<int>>& mat, int target) {
    // // Brute Force
    // int n = mat.size();
    // int m = mat[0].size();
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(mat[i][j] == target){
    //             return true;
    //             break;
    //         }
    //     }
    // }
    // return false;

    // Binary Search
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = (n*m-1);
    while(low<=high){
        int mid = low + (high-low)/2;
        int row = mid / m; 
        int col = mid % m;
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) low = mid + 1;
        else  high = mid -1;
    }
    return false;
}