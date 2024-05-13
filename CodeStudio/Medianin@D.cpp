int median(vector<vector<int>> &matrix, int m, int n) {
    // Brute force O(N2 + NLoGN)
    vector<int> ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans.push_back(matrix[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    int k = ans.size();
    if(k % 2 == 1) return ans[k/2];
    return ((double)(n + (n-1))) / 2.0;
    
}