vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans = ans * (row-col);
        ans = ans/ (col);
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int N) {
    // // finding a particular element
    // // Use nCr
    // int ncr(int N, int element){
    //     int res = 1;
    //     for(int i=0;i<r;i++){
    //         res = res * (n-1);
    //         res = res/(i+1);
    //     }
    //      return res;   //Outputs a result
    // }

//    Printing N values
    vector<vector<int>> ans;
    for(int i=1;i<=N;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}