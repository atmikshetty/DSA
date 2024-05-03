#include<bits/stdc++.h>

int findKRotation(vector<int> &arr){
    // Write your code here.    
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans  = INT_MAX;
    int ind = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                ind = low;
                ans = arr[low];
            }
            low = mid + 1;
        }else{
            if(arr[mid]<ans){
                ind = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return ind;
}