#include<bits/stdc++.h>

int lowerBound(vector<int> arr, int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // // Brute Force (NxM)
    // int ind = -1;
    // int maxCount = 0;
    // for(int i=0;i<n-1;i++){
    //     int countRow = 0;
    //     for(int j=0;j<m-1;j++){
    //         countRow += matrix[i][j];
    //     }
    //     if(countRow > maxCount){
    //         maxCount = countRow;
    //         ind = i;
    //     }
    // }
    // return ind;

    // Binary Search
    int ind = -1;
    int maxCount = 0;
    for(int i=0;i<n;i++){
        int count = m - lowerBound(matrix[i], m, 1);
        if(count > maxCount){
            maxCount = count;
            ind = i;
        }
    }
    return  ind;
}