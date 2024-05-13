int findMaxRow(vector<vector<int>> &arr, int n, int m, int col){
    int maxi  = -1;
    int ind = -1;
    for(int i=0;i<n;i++){
        if(arr[i][col] > maxi){
            maxi = arr[i][col];
            ind = i;
        }
    }
    return ind;
}

vector<int> findPeakGrid(vector<vector<int>> &g){
   int n = g.size();
   int m = g[0].size();
   int low = 0, high = m-1;
   while(low<=high){
       int mid = low + (high-low)/2;
       int maxRowIndex = findMaxRow(g, n, m, mid);
       int left = mid - 1 >= 0 ? g[maxRowIndex][mid-1] : -1;
       int right = mid + 1 < m ? g[maxRowIndex][mid+1] : -1;
       if(g[maxRowIndex][mid]>left && g[maxRowIndex][mid] > right){
           return {maxRowIndex, mid};
       }
       else if(g[maxRowIndex][mid] < left){
           high = mid - 1;
       }else {
           low = mid + 1;
       }
   } 
   return {-1,-1};
}