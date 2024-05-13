#include <bits/stdc++.h> 

int BS(vector<int> arr, int target){
    int low = 0;
    int high = arr.size();
    while(low<=high){
        int mid=  low + (high-low)/2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

bool findInMatrix(int x, vector<vector<int>> &arr)
{
    //    Brute force O(N2)
    int n = arr.size();
    int m = arr[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == x) return true;
        }
    }
    return false;

    // Binary Search on 1D Arrays (Log2N * O(N))
    int ind;
    int n = arr.size();
    for(int i=0;i<n;i++){
        int ans = BS(arr[i], x);
        if(ans != -1) return true;
    }
    return false;

    Binary Search Optimised
    int n = arr.size();
    int m = arr[0].size();
    int row = 0;
    int col = m -1 ;
    while(row<n && col >= 0){
        if(arr[row][col] == x) return true;
        else if(arr[row][col] < x) row ++;
        else col--;
    }
    return false;
}